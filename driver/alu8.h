#ifndef _ALU8_H
#define _ALU8_H

#include "miscdefs.h"

struct ALU8 {

    uint32_t ctlpins;
    uint16_t ir;
    uint8_t ain, bin;
    bool cin, shrin;

    void compute ();

    bool aena;
    bool bnot;
    uint8_t enablda;
    uint8_t nottedb;

    char opchar;
    uint8_t dout;
    bool cout;
    bool vout;
    bool shrout;
};

#endif
