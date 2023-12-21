#ifndef _TIME_H
#define _TIME_H

typedef __uint32_t time_t;

struct tm {
    int tm_sec;     // 00..59
    int tm_min;     // 00..59
    int tm_hour;    // 00..23
    int tm_mday;    // 01..31
    int tm_mon;     // 00..11
    int tm_year;    // 0=1900
    int tm_wday;    // 0=Sunday
    int tm_yday;    // 000..365
    int tm_isdst;
};

time_t time (time_t *tp);
tm *gmtime (time_t const *tp);
tm *gmtime_r (time_t const *tp, tm *tmbuf);
time_t timegm (tm const *tmbuf);

#endif
