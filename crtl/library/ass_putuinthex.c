#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putptr (void *ptr)
{
    ass_putuinthex ((__size_t) ptr);
}

void ass_putuinthex (unsigned int val)
{
    char num[12];
    int len = 12;
    do {
        char chr = val % 16 + '0';
        if (chr > '9') chr += 'A' - '0' - 10;
        num[--len] = chr;
        val /= 16;
    } while (val > 0);
    ass_putbuf (num + len, 12 - len);
}

