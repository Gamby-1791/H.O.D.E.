/**
 * Module input parameter.
 */

public class IParam extends OpndLhs {
    public int index;

    public IParam (String name, int index)
    {
        this.name  = name;
        this.index = index;
    }

    // don't allow writing to an input pin
    @Override
    public String addWriter (WField wfield)
    {
        return "cannot write to an input pin";
    }

    // input pins are good without any writers
    @Override
    public String checkWriters ()
    {
        return null;
    }

    // the only input pins we should have at netlist generation time are for the top-level
    // module.  should only be needed for testing netlist generation, as real circuit boards
    // don't have input pins, just real connectors with input pins which are an actual
    // circuit element.
    @Override
    public Network generate (GenCtx genctx, int rbit)
    {
        String netname = (rbit + lodim) + "." + name;
        Network net = genctx.nets.get (netname);
        if (net == null) {
            net = new Network (genctx, netname);
            assert genctx.nets.get (netname) == net;
        }
        return net;
    }

    // nop for simulator
    // assume simulator has set input pin values with
    // force command for this t before calling any stepSim()
    @Override
    public boolean forceable ()
    {
        return true;
    }
    @Override
    protected void stepSimWork (int t)
    { }
}
