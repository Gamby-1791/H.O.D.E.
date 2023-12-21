#include <stdio.h>
#include <time.h>

int main ()
{
    struct timespec lastts, thists;
    unsigned long long lastns, thisns;

    while (1) {
        clock_gettime (CLOCK_MONOTONIC_RAW, &lastts);
        clock_gettime (CLOCK_MONOTONIC_RAW, &thists);
        lastns = lastts.tv_sec * 1000000000ULL + lastts.tv_nsec;
        thisns = thists.tv_sec * 1000000000ULL + thists.tv_nsec;
        printf ("%20llu - %20llu = %20llu\n", thisns, lastns, thisns - lastns);
    }
}
