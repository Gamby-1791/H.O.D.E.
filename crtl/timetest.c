#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv)
{
    __uint64_t lastnow = 0;
    for (int i = 0; i < 1000; i ++) {
        __uint64_t nowns = getnowns ();
        __uint64_t diff = nowns - lastnow;
        printf ("nowns=%Qu dt=%Qu\n", nowns, diff);
        lastnow = nowns;
    }
}
