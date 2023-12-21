#include <assert.h>
#include <stdlib.h>

void abort ()
{
    ass_putstr ("\nabort: called from PC="); ass_putptr (__retaddr); ass_putchr ('\n');
    exit (255);
}
