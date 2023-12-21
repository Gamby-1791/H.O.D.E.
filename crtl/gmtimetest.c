#include <stdio.h>
#include <time.h>

int main (int argc, char **argv)
{
    time_t tmbin = 0;
    do {
        struct tm *tmbuf = gmtime (&tmbin);
        time_t     rebin = timegm (tmbuf);
        unsigned int tmday = tmbin / 86400;
        unsigned int reday = rebin / 86400;
        printf ("%04d-%02d-%02d %02d %03d  %5u %5u %5d\n",
                    tmbuf->tm_year + 1900, tmbuf->tm_mon + 1, tmbuf->tm_mday,
                    tmbuf->tm_wday, tmbuf->tm_yday,
                    tmday, reday, reday - tmday);
        tmbin += 86400;
    } while ((__uint32_t)tmbin >= 86400);
    return 0;
}
