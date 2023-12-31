#include "alu8.h"
#include "gpiolib.h"

void ALU8::compute ()
{
    bool irfc  = (ctlpins & C_ALU_IRFC)  != 0;
    bool bonly = (ctlpins & C_ALU_BONLY) != 0;
    bool add   = (ctlpins & C_ALU_ADD)   != 0;
    bool ir0   =  ir       & 1;
    bool ir1   = (ir >> 1) & 1;
    bool ir2   = (ir >> 2) & 1;
    bool ir3   = (ir >> 3) & 1;

    bool doaddsub = (irfc &  ir2) | add;                        // MOV,NEG,INC,COM,ADD,SUB,ADC,SBB
    bool doingior = (irfc &  ir3 & !ir2 & !ir1 & !ir0) | bonly; // OR
    bool doingand =  irfc &  ir3 & !ir2 & !ir1 &  ir0;          // AND
    bool doingxor =  irfc &  ir3 & !ir2 &  ir1 & !ir0;          // XOR
    bool doingshr =  irfc & !ir3 & !ir2;                        // LSR,ASR,ROR
    aena = add | (ir3 & !bonly) | doingshr;                     // LSR,ASR,ROR,OR,AND,XOR,ADD,SUB,ADC,SBB
    bnot = ir0 & irfc & ir2;                                    // NEG,COM,SUB,SBB

    if (! aena) ain = 0;                                        // aluboard2 jams ain=0 when a not enabled

    uint8_t nottedb = bnot ? ~bin : bin;

    opchar = 0;
    dout   = 0;
    if (doaddsub) { opchar |= '+'; dout |= ain + nottedb + cin; }
    if (doingior) { opchar |= '|'; dout |= ain | nottedb; }
    if (doingand) { opchar |= '&'; dout |= ain & nottedb; }
    if (doingxor) { opchar |= '^'; dout |= ain ^ nottedb; }
    if (doingshr) { opchar |= '>'; dout |= (shrin ? 0x80 : 0x00) | (ain >> 1); }
    if (opchar == 0) opchar = '?';

    cout   = ((uint32_t) ain + (uint32_t) nottedb + cin) > 0xFF;
    vout   = ((uint32_t) (ain & 0x7F) + (uint32_t) (nottedb & 0x7F) + cin) > 0x7F;
    shrout = ain & 1;
}
