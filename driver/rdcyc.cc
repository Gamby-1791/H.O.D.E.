#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rdcyc.h"

static int numcores = -1;

void rdcycinit ()
{
    if (numcores < 0) {
        char infoline[256];
        FILE *infofile = fopen ("/proc/cpuinfo", "r");
        if (infofile == NULL) abort ();
        while (fgets (infoline, sizeof infoline, infofile) != NULL) {
            if (memcmp (infoline, "processor\t:", 11) == 0) {
                int n = atoi (infoline + 11) + 1;
                if (numcores < n) numcores = n;
            }
        }
        fclose (infofile);
        fprintf (stderr, "rdcycinit:: num cores %d\n", numcores);
        if (numcores <= 0) abort ();
#ifdef UNIPROC
        if (UNIPROC && (numcores > 1)) {
            fprintf (stderr, "rdcycinit:: UNIPROC set but have %d cores\n", numcores);
            abort ();
        }
#endif
    }

    // stay on one core so rdcyc() will work
    if (numcores > 1) {
        cpu_set_t cpuset;
        CPU_ZERO (&cpuset);
        CPU_SET (1, &cpuset);
        if (sched_setaffinity (0, sizeof cpuset, &cpuset) < 0) {
            abort ();
        }
    }
}

void rdcycuninit ()
{
    // not main thread, any core will do
    if (numcores > 1) {
        cpu_set_t cpuset;
        CPU_ZERO (&cpuset);
        for (int i = numcores; -- i >= 0;) {
            CPU_SET (i, &cpuset);
        }
        if (sched_setaffinity (0, sizeof cpuset, &cpuset) < 0) {
            abort ();
        }
    }
}

uint32_t rdcycfreq ()
{
    uint32_t begtime = time (NULL);
    while ((uint32_t) time (NULL) == begtime) { }
    uint32_t startcycle = rdcyc ();
    uint32_t midtime = time (NULL);
    while ((uint32_t) time (NULL) == midtime) { }
    uint32_t stopcycle = rdcyc ();
    return stopcycle - startcycle;
}

// read raspi cycle counter
uint32_t rdcyc (void)
{
#if HASTSC
#ifdef __aarch64__
    uint64_t cyc;
    asm volatile ("mrs %0,cntvct_e10" : "=r" (cyc));
    return cyc;
#endif
#ifdef __ARM_ARCH
    uint32_t cyc;
    asm volatile ("mrc p15,0,%0,c9,c13,0" : "=r" (cyc));
    return cyc;
#endif
#ifdef __i386__
    uint32_t cyc;
    asm volatile ("rdtsc" : "=a" (cyc) :: "edx");
    return cyc;
#endif
#ifdef __x86_64__
    uint32_t cyc;
    asm volatile ("rdtsc" : "=a" (cyc) :: "edx");
    return cyc;
#endif
#else
    struct timespec nowts;
    if (clock_gettime (CLOCK_MONOTONIC, &nowts) < 0) abort ();
    return nowts.tv_nsec + nowts.tv_sec * 1000000000;
#endif
}
