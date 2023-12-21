#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putdbl (double dbl)
{
    if (isnan (dbl)) {
        ass_putstr ("nan");
        return;
    }
    if (dbl < 0.0) {
        ass_putchr ('-');
        dbl = - dbl;
    }
    if (! isfinite (dbl)) {
        ass_putstr ("inf");
    } else if (dbl == 0.0) {
        ass_putstr ("0.0");
    } else if (dbl < 0.001) {
        dbl *= 10000.0;
        int exp = 0;
        while (dbl < 0.001) { exp -= 5; dbl *= 100000.0; }
        while (dbl < 1000.0) { -- exp; dbl *= 10.0; }
        int num = (int) (dbl + 0.5);
        ass_putint (num / 10000);
        ass_putchr ('.');
        ass_putint (num % 10000);
        ass_putchr ('e');
        ass_putint (exp);
    } else if (dbl > 1000.0) {
        int exp = 0;
        while (dbl >= 1000000.0) { exp += 5; dbl /= 100000.0; }
        while (dbl >= 1.0) { exp ++; dbl /= 10.0; }
        dbl *= 10000.0;
        int num = (int) (dbl + 0.5);
        ass_putint (num / 10000);
        ass_putchr ('.');
        ass_putint (num % 10000);
        ass_putstr ("e+");
        ass_putint (exp);
    } else {
        dbl += 0.00005;
        int i = (int) dbl;
        ass_putint (i);
        ass_putchr ('.');
        for (int j = 4; -- j >= 0;) {
            dbl -= i;
            dbl *= 10.0;
            i = (int) dbl;
            ass_putchr ((char) ('0' + i));
        }
    }
}

