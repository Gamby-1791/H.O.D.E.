#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putflt (float flt)
{
    if (isnanf (flt)) {
        ass_putstr ("nan");
        return;
    }
    if (flt < 0.0) {
        ass_putchr ('-');
        flt = - flt;
    }
    if (! isfinitef (flt)) {
        ass_putstr ("inf");
    } else if (flt == 0.0) {
        ass_putstr ("0.0");
    } else if (flt < 0.001) {
        flt *= 10000.0;
        int exp = 0;
        while (flt < 0.001) { exp -= 5; flt *= 100000.0; }
        while (flt < 1000.0) { -- exp; flt *= 10.0; }
        int num = (int) (flt + 0.5);
        ass_putint (num / 10000);
        ass_putchr ('.');
        ass_putint (num % 10000);
        ass_putchr ('e');
        ass_putint (exp);
    } else if (flt > 1000.0) {
        int exp = 0;
        while (flt >= 1000000.0) { exp += 5; flt /= 100000.0; }
        while (flt >= 1.0) { exp ++; flt /= 10.0; }
        flt *= 10000.0;
        int num = (int) (flt + 0.5);
        ass_putint (num / 10000);
        ass_putchr ('.');
        ass_putint (num % 10000);
        ass_putstr ("e+");
        ass_putint (exp);
    } else {
        flt += 0.00005;
        int i = (int) flt;
        ass_putint (i);
        ass_putchr ('.');
        for (int j = 4; -- j >= 0;) {
            flt -= i;
            flt *= 10.0;
            i = (int) flt;
            ass_putchr ((char) ('0' + i));
        }
    }
}

