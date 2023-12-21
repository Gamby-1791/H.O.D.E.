/**
 * Access a read-only view of sub-field of an operand.
 */

import java.io.PrintStream;

public class RField extends OpndRhs {
    public OpndLhs refdopnd;    // operand being accessed
    public int lodim;           // bits within that operand
    public int hidim;

    //// GENERATION ////

    @Override
    public Network generate (GenCtx genctx, int rbit)
    {
        return refdopnd.generate (genctx, lodim - refdopnd.lodim + rbit);
    }

    @Override
    public void printProp (PropPrinter pp, int rbit)
    {
        refdopnd.printProp (pp, lodim - refdopnd.lodim + rbit);
    }

    //// SIMULATION ////

    @Override
    protected int busWidthWork ()
    {
        assert hidim >= lodim;
        return hidim - lodim + 1;
    }

    @Override
    protected void stepSimWork (int t)
            throws HaltedException
    {
        assert lodim >= refdopnd.lodim;
        long in = refdopnd.getSimOutput (t);
        setSimOutput (t, in >>> (lodim - refdopnd.lodim));
    }
}
