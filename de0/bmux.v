// generate misc BBUS values
// combinational logic only
//  input:
//   IR = instruction register
//   CON_0 = output a 0
//   CON_2 = output a 2
//   CON__4 = output a -4
//   IRBROF = output sign-extended branch offset
//   IRLSOF = output sign-extended liad/store offset
//  output:
//   Q = resultant output (0 if nothing selected)

module bmux (IR, CON_0, CON_2, CON__4, IRBROF, IRLSOF, Q);
    input[15:00] IR;
    input CON_0, CON_2, CON__4, IRBROF, IRLSOF;
    output[15:00] Q;

    wire[15:00] irbrof = { {6 {IR[09]}}, IR[09:01], 1'b0 };
    wire[15:00] irlsof = { {9 {IR[06]}}, IR[06:00] };

    assign Q = (CON_2 ? 16'h0002 : 16'h0) | (CON__4 ? 16'hFFFC : 16'h0) | (IRBROF ? irbrof : 16'h0) | (IRLSOF ? irlsof : 16'h0);
endmodule
