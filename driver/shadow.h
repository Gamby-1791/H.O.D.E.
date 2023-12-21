#ifndef _SHADOW_H
#define _SHADOW_H

#include "gpiolib.h"
#include "miscdefs.h"

struct Shadow {
    enum State {
        RESET0, RESET1, FETCH1, FETCH2, 
        BCC1, ARITH1,
        STORE1, STORE2, LDA1, LOAD1, LOAD2, LOAD3,
        WRPS1, RDPS1, IRET1, IRET2, IRET3, IRET4,
        HALT1, IREQ1, IREQ2, IREQ3, IREQ4, IREQ5
    };

    bool chkacid;
    bool printinstr;
    bool printstate;

    State state;
    uint16_t ir;
    uint16_t regs[8];
    uint16_t psw;

    Shadow ();
    void open (GpioLib *gpiolib);
    void reset ();
    bool check (uint32_t sample);
    bool clock (uint16_t mq, bool irq);
    uint64_t getcycles ();
    uint32_t readgpio ();

private:
    bool fatal;
    GpioLib *gpiolib;
    int rawcmid;
    int rawcout;
    int rawvout;
    State states[8];
    uint16_t alu;
    uint16_t newpsw;
    uint32_t samples[8];
    uint64_t cycle;

    State endOfInst (bool irq);
    bool branchTrue ();
    void loadPsw (uint16_t newpsw);
    void puque ();
    void check_g (uint32_t sample, uint32_t gtest, uint32_t gdont);
    void check_a (uint16_t asb);
    void check_b (uint16_t bsb);
    void check_c (uint32_t csb, uint32_t cdc);
    void check_d (uint16_t dsb);
    void check_d (uint32_t dsb, uint32_t mask);
    void check_i (uint16_t isb);

    static char const *boolstr (bool b);
    static char const *statestr (State s);
};

#endif
