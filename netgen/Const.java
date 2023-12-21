/**
 * Numeric constants in source code.
 */

import java.io.PrintStream;

public class Const extends OpndRhs {
    public Token.Int token;

    //// GENERATION ////

    @Override
    public Network generate (GenCtx genctx, int rbit)
    {
        return genctx.nets.get ((((token.value >> rbit) & 1) == 0) ? "GND" : "VCC");
    }

    @Override
    public void printProp (PropPrinter pp, int rbit)
    {
        pp.println ("Const", this, rbit);
    }

    //// SIMULATION ////

    @Override
    protected int busWidthWork ()
    {
        if (token.width > 0) return token.width;
        for (int w = 1; w < 32; w ++) {
            if (token.value >>> w == 0) return w;
        }
        return 32;
    }

    @Override
    protected void stepSimWork (int t)
    {
        setSimOutput (t, (token.value << 32) | ((~token.value) & 0xFFFFFFFFL));
    }
}
