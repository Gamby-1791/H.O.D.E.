#include <stdarg.h>
#include <stdio.h>

#include "fdfile.h"

int dprintf (int fd, char const *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    int rc = vdprintf (fd, fmt, ap);
    va_end (ap);
    return rc;
}

int vdprintf (int fd, char const *fmt, va_list ap)
{
    FDFILE stream;
    stream.fd = fd;
    int rc = vfprintf (&stream, fmt, ap);
    stream.fd = -1;
    return rc;
}
