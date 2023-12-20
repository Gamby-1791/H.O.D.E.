// gate memory read data onto BBUS
//  input:
//   D = data from memory
//   WORD = data is word sized; else byte sized
//   RE = enable gating onto output; else output 0
//   SEXT = sign-extend byte; else zero-extend byte; ignored if WORD mode
//  output:
//   Q = resultant output

module memrd (D, WORD, RE, SEXT, Q);
    input[15:00] D;
    input WORD, RE, SEXT;

    output[15:00] Q;

    assign Q[07:00] = RE ? D[07:00] : 8'b0;
    assign Q[15:08] = RE & WORD ? D[15:08] : RE & SEXT ? {8 {D[07]}} : 8'b0;
endmodule
