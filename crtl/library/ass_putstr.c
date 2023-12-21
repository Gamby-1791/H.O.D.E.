#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ass_putstr (char const *str)
{
    int len = strlen (str);
    ass_putbuf (str, len);
}

