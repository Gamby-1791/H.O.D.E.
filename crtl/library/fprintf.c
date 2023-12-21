#include <stdarg.h>
#include <stdio.h>

int printf (char const *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    int rc = vprintf (fmt, ap);
    va_end (ap);
    return rc;
}

int fprintf (FILE *stream, char const *fmt, ...)
{
    va_list ap;
    va_start (ap, fmt);
    int rc = vfprintf (stream, fmt, ap);
    va_end (ap);
    return rc;
}

int vprintf (char const *fmt, va_list ap)
{
    return vfprintf (stdout, fmt, ap);
}
