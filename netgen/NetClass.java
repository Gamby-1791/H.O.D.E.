import java.util.LinkedList;

public class NetClass {
    public final String name;
    public final String attr;
    public final LinkedList<Network> networks;

    public NetClass (String name, String attr)
    {
        this.name = name;
        this.attr = attr;
        networks  = new LinkedList<> ();
    }
}
