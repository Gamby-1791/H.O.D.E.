#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void assertfail (char const *file, int line)
{
    ass_putstr ("assertfail: ");
    ass_putstr (file);
    ass_putchr (' ');
    ass_putint (line);
    ass_putchr ('\n');
    exit (1);
}

