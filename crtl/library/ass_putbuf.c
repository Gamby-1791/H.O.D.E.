#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putbuf (char const *str, int len)
{
    while (len > 0) {
        int rc = write (2, str, len);
        if (rc <= 0) exit (9999);
        str += rc;
        len -= rc;
    }
}
