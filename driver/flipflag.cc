#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gpiolib.h"
#include "miscdefs.h"

static GpioLib *gpio;
static uint64_t ncycles;

int main (int argc, char **argv)
{
    uint32_t cpuhz = DEFCPUHZ;

    setlinebuf (stdout);

    for (int i = 0; ++ i < argc;) {
        if (strcasecmp (argv[i], "-cpuhz") == 0) {
            if ((++ i >= argc) || (argv[i][0] == '-')) {
                fprintf (stderr, "-cpuhz missing freq\n");
                return 1;
            }
            cpuhz = atoi (argv[i]);
            continue;
        }
        if (argv[i][0] == '-') {
            fprintf (stderr, "unknown option %s\n", argv[i]);
            return 1;
        }
        fprintf (stderr, "unknown argument %s\n", argv[i]);
        return 1;
    }

    gpio = new PhysLib (cpuhz, true);
    gpio->open ();

    uint32_t lasttime = time (NULL);
    uint64_t lastcycs = 0;

    while (true) {

        uint32_t thistime = time (NULL);
        if (thistime / 60 > lasttime / 60) {
            printf ("%02u:%02u:%02u %13llu cycles  %6llu Hz  %10.3f uS\n",
                        thistime / 3600 % 24, thistime / 60 % 60, thistime % 60,
                        ncycles, (ncycles - lastcycs) / (thistime - lasttime),
                        (thistime - lasttime) * 1000000.0 / (ncycles - lastcycs));
            lasttime = thistime;
            lastcycs = ncycles;
        }

        ncycles ++;
        gpio->writegpio (false, G_RESET | G_FLAG);
        gpio->halfcycle ();
        //system ("./raspi-gpio get 27");
        gpio->writegpio (false, G_CLK);
        gpio->halfcycle ();
        //system ("./raspi-gpio get 27");
    }

    return 0;
}
