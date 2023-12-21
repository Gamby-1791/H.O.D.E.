// measure cpu clock frequency
// cc -Wall -O2 -o testhz.`uname -m` testhz.cc rdcyc.cc
// ./testhz.`uname -m`

#include <stdio.h>
#include <time.h>

#include "rdcyc.h"

int main ()
{
    rdcycinit ();
    time_t start = time (NULL);
    while (time (NULL) == start) { }
    uint32_t beg = rdcyc ();
    ++ start;
    while (time (NULL) == start) { }
    uint32_t end = rdcyc ();
    printf ("%u\n", end - beg);
    return 0;
}
