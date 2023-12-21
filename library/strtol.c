#include <errno.h>
#include <stdlib.h>

long strtol (char const *nptr, char **endptr, unsigned int base)
{
    char ch;
    while ((ch = *nptr) != 0) {
        if (ch >= ' ') break;
        nptr ++;
    }

    bool neg = ch == '-';
    nptr += neg;

    long value = strtoul (nptr, endptr, base);

    if ((value < 0) && (value != 0x7FFFFFFF + neg)) {
        errno = ERANGE;
        value = 0x7FFFFFFF + neg;
    }
    if (neg) value = - value;
    return value;
}
