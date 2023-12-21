#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putuint (unsigned int val)
{
    char num[12];
    int len = 12;
    do {
        num[--len] = val % 10 + '0';
        val /= 10;
    } while (val > 0);
    ass_putbuf (num + len, 12 - len);
}

