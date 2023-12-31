// processor status word register
//  input:
//   D = data bus (alu output)
//   CLOCK = write psw on low-to-high transition
//   WE = write psw at end of cycle from D input
//   IECLR = immediately clear interrupt enable
//   ALUWE = write psw n,z,v,c bits at end of cycle from ALU{N,Z,V,C} inputs
//   ALU{N,Z,V,C} = result outputs from alu
//   RE = gate psw contwnts onto output (Q)
//   IR = instruction register
//  output:
//   Q = psw contents if RE set, else 0
//   IE = contents of psw ie bit
//   N,Z,V,C = contents of psw n,z,v,c bits
//   BT = assuming ir contains a branch instruction, the branch condition is true

module psw (D, CLOCK, WE, IECLR, ALUWE, ALUN, ALUZ, ALUV, ALUC, RE, IR, Q, IE, N, Z, V, C, BT);
    input CLOCK, WE, IECLR, ALUWE, ALUN, ALUZ, ALUV, ALUC, RE;
    input[15:00] D, IR;
    output[15:00] Q;
    output IE, N, Z, V, C, BT;

    reg ieff, nff, zff, vff, cff;

    assign Q  = {16 {RE}} & { ieff, 11'b11111111111, nff, zff, vff, cff };
    assign IE = ieff;
    assign N  = nff;
    assign Z  = zff;
    assign V  = vff;
    assign C  = cff;

    wire nv = N ^ V;
    wire _btbase = ~(                           // 000 : never
        (~IR[12] & IR[11] & nv) |               // 01x : BLT/BLE
        (IR[12] & ~IR[11] & cff)  |             // 10x : BLO/BLOS
        (~(IR[12] & IR[11]) & IR[10] & zff) |   // 001,011,101 : BEQ,BLE,BLOS
        (IR[12] & IR[11] & ~IR[10] & nff) |     // 110 : BMI
        (IR[12] & IR[11] & IR[10] & vff));      // 111 : BVS
    assign BT = ~IR[00] ^ _btbase;
	 
	 always @ (posedge IECLR or posedge CLOCK) begin
	     if (IECLR) begin
		      ieff <= 0;
        end else if (WE) begin
            ieff <= D[15];
		  end
	 end
	 always @ (posedge CLOCK) begin
		  if (WE) begin
            nff  <= D[03];
            zff  <= D[02];
            vff  <= D[01];
            cff  <= D[00];
        end else if (ALUWE) begin
            nff  <= ALUN;
            zff  <= ALUZ;
            vff  <= ALUV;
            cff  <= ALUC;
        end
    end
endmodule
