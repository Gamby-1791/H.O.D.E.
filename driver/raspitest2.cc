/**
 * Tests clocking flipflops on the pb2board.
 */

#include <errno.h>
#include <fcntl.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "gpiolib.h"
#include "rdcyc.h"

#define ever (;;)

static PhysLib gpio (DEFCPUHZ);

int main (int argc, char **argv)
{
    if (argc != 2) {
        fprintf (stderr, "usage: raspitest2 <freqhz>\n");
        return 1;
    }
    int freqhz = atoi (argv[1]);

    rdcycinit ();
    uint32_t rcfreq = rdcycfreq ();
    printf ("rdcycfreq = %u\n", rcfreq);
    uint32_t fullcycle = rcfreq / freqhz;
    uint32_t halfcycle = fullcycle / 2;

    gpio.open ();

    uint32_t lastcount = 0;

    uint64_t nloops = 0;
    uint32_t errors = 0;

    time_t begtime = time (NULL);

    for ever {
        if (++ nloops % freqhz == 0) {
            time_t nowtime = time (NULL);
            if (nowtime > begtime) {
                printf (" %u*%llu/%llu", errors, nloops, nloops / (nowtime - begtime));
                fflush (stdout);
            }
        }

        gpio.writegpio (false, G_CLK);
        uint32_t begcycle = rdcyc ();
        while (rdcyc () - begcycle < halfcycle) { }

        gpio.writegpio (false, 0);
        begcycle = rdcyc ();
        while (rdcyc () - begcycle < halfcycle) { }

        uint32_t value = gpio.readgpio ();
        uint32_t count = ((value / (G_HALT / 8)) & 8) | ((value / (G_WRITE / 4)) & 4) | ((value / (G_READ / 2)) & 2) | ((value / G_WORD) & 1);
        if ((count - lastcount) % 16 != 1) {
            printf ("\nerror:  %X -> %X\n", lastcount, count);
            ++ errors;
        }
        lastcount = count;
    }
}
