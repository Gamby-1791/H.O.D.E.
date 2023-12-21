import java.util.LinkedList;

public class PropNode {
    public PropNode parent;
    public OpndRhs opnd;
    public int level;
    public int rbit;
    public LinkedList<PropNode> childs;
    public String type;

    @Override
    public String toString ()
    {
        return String.format ("%05d%" + (level * 2 + 1) + "s%s %s[%d]",
                    level, "", type.toString (), ((opnd == null) ? "<null>" : opnd.name), rbit);
    }
}
