#include <stdint.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    FILE *profile = fopen ("raspictl.readcounts", "r");
    if (profile == NULL) {
        fprintf (stderr, "error opening raspictl.readcounts: %m\n");
        return -1;
    }
    uint32_t addr, count;
    for (addr = 0; addr < 65536; addr += 2) {
        if (fread (&count, sizeof count, 1, profile) <= 0) break;
        printf ("%12u : %04X\n", count, addr);
    }
    return 0;
}
