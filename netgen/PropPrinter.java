import java.util.LinkedList;

public class PropPrinter {
    public PropNode currnode;

    public void inclevel ()
    {
        currnode = currnode.childs.getLast ();
    }

    public void declevel ()
    {
        currnode = currnode.parent;
    }

    public void println (String type, OpndRhs opnd, int rbit)
    {
        PropNode node = new PropNode ();
        node.parent = currnode;
        node.level  = currnode.level + 1;
        node.type   = type;
        node.opnd   = opnd;
        node.rbit   = rbit;

        if (currnode.childs == null) {
            currnode.childs = new LinkedList<> ();
        }
        currnode.childs.add (node);
    }
}
