#include <errno.h>
#include <stdio.h>

char const *strerror (int e)
{
    static char buf[20];
    sprintf (buf, "errno=%d", e);
    return buf;
}
