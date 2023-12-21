#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putchr (char chr)
{
    ass_putbuf (&chr, 1);
}

