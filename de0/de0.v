// top-level module that interfaces wirh raspi
// inverts signals cuz raspictl program assumes that
// also switches mbus on command by raspi

module de0 (_CLOCK, _DENA, _INTRQ, _RESET, _HALT, _MREAD, _MWORD, _MWRITE, _MBUS, LEDS, STATES);
    input _CLOCK, _DENA, _INTRQ, _RESET;
    output _HALT, _MREAD, _MWORD, _MWRITE;
    inout[15:00] _MBUS;
    output[7:0] LEDS;
    output[23:00] STATES;

    wire halt, mread, mword, mwrite;
    wire[15:00] md;

    assign _HALT   = ~ halt;
    assign _MREAD  = ~ mread;
    assign _MWORD  = ~ mword;
    assign _MWRITE = ~ mwrite;
    assign _MBUS   = _DENA ? 16'hZZZZ : ~ md;
    assign LEDS    = md[7:0];

    sys sys (.CLOCK (~ _CLOCK), .INTRQ (~ _INTRQ), .RESET (~ _RESET), .MQ (~ (_MBUS & {16 {_DENA}})),
            .HALT (halt), .MREAD (mread), .MWORD (mword), .MWRITE (mwrite), .MD (md), .STATES (STATES));
endmodule
