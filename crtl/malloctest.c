#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKSIZE(b) (*(__size_t *)((__size_t)b - 14));

int main (int argc, char **argv)
{
    void *alloclist = NULL;
    __size_t totalalloc = 0;
    __size_t numblocks = 0;

    printf ("starting\n");

    while (1) {
        __uint16_t nowns = (__uint16_t) getnowns ();
        __size_t size = nowns & 2047;
        if ((nowns & 256) && (totalalloc < 40*1024 - size)) {
            printf ("malloc size=%u\n", size);
            void *newalloc = malloc (size);
            *(void **)newalloc = alloclist;
            alloclist = newalloc;
            totalalloc += BLOCKSIZE (newalloc);
            numblocks ++;
            printf ("numblocks=%u totalalloc=%u\n", numblocks, totalalloc);
        } else if (alloclist != NULL) {
            void *freeblock = alloclist;
            totalalloc -= BLOCKSIZE (freeblock);
            alloclist = *(void **)freeblock;
            free (freeblock);
            -- numblocks;
            printf ("numblocks=%u totalalloc=%u\n", numblocks, totalalloc);
        }
    }
}
