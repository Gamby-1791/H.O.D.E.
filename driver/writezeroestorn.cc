/**
 * Program runs on any computer to test a physical register board jumpered for a particular register.
 * Requires four IOW56Paddles connected to the A,C,I,D connectors.
 * sudo insmod km/enabtsc.ko
 * sudo ./writezeroestor5 [-cpuhz 200] [-count] 0..7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "gpiolib.h"
#include "miscdefs.h"

static GpioLib *gpio;

static void writeccon (uint32_t pins);
static void writeibus (uint16_t ibus);
static void writedbus (uint16_t dbus);
static void checkabbusses (uint16_t abus);

int main (int argc, char **argv)
{
    bool count = false;
    char *p;
    int regnum = -1;
    uint32_t counter = 0;
    uint32_t cpuhz = DEFCPUHZ;

    setlinebuf (stdout);

    for (int i = 0; ++ i < argc;) {
        if (strcasecmp (argv[i], "-count") == 0) {
            count = true;
            continue;
        }
        if (strcasecmp (argv[i], "-cpuhz") == 0) {
            if (++ i >= argc) {
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
        if (regnum < 0) {
            regnum = strtol (argv[i], &p, 0);
            if ((*p == 0) && (regnum >= 0) && (regnum <= 7)) continue;
        }
        fprintf (stderr, "unknown argument %s\n", argv[i]);
        return 1;
    }

    // access regboard circuitry via paddles
    gpio = new PhysLib (cpuhz);
    gpio->open ();

    writeccon (0);
    writeibus ((regnum << REGA) | (regnum << REGB) | (regnum << REGD));
    gpio->halfcycle ();


    while (true) {
        writedbus (counter);
        writeccon (C_GPRS_WED | C_GPRS_REA | C_GPRS_REB);
        gpio->halfcycle ();
        writeccon (C_GPRS_WED | C_GPRS_REA | C_GPRS_REB | C_CLK2);
        gpio->halfcycle ();
        checkabbusses (counter);

        if (count) counter ++;
    }

    return 0;
}

// write control output pins that regboards care about
// all other ccon pins get random values
static void writeccon (uint32_t pins)
{
    uint32_t mask = C_CLK2 | C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA | C_GPRS_REB | C_GPRS_RED2B | C_GPRS_REA7;
    ASSERT ((pins & ~ mask) == 0);
    pins |= rand () & ~ mask;
    if (! gpio->writecon (CON_C, 0xFFFFFFFF, pins)) {
        abort ();
    }
}

// write value being sent out over the instruction register connector
static void writeibus (uint16_t ibus)
{
    uint32_t icon = GpioLib::ibusshuf (ibus);
    if (! gpio->writecon (CON_I, 0xFFFFFFFF, icon)) {
        abort ();
    }
}

// write dbus value that goes to all register dff inputs
// all other dcon pins get random values
static void writedbus (uint16_t dbus)
{
    ASSERT (D_DBUS == 0xFFFF);
    uint32_t pins = GpioLib::dbusshuf (dbus) | (rand () << 16);
    if (! gpio->writecon (CON_D, 0xFFFFFFFF, pins)) {
        abort ();
    }
}

static void checkabbusses (uint16_t abus)
{
    uint32_t acon;
    if (! gpio->readcon (CON_A, &acon)) {
        abort ();
    }
    uint16_t ais = GpioLib::abussort (acon);
    uint16_t bis = GpioLib::bbussort (acon);
    printf ("abus is=%04X  bbus is=%04X  sb=%04X  diff=%04X\n", ais, bis, abus, ais ^ abus);
}
