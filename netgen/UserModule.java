/**
 * One of these per module in source code.
 * Also gets extended by BIModule each built-in module.
 */

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.TreeMap;

public class UserModule extends Module {
    public Token tokstart;  // starting '{' in source code

    // make an array of wires corresponding to instantiated module and insert into target module
    // caller can then use them in assignment-like constructs to match with arguments
    @Override
    public OpndLhs[] getInstParams (UserModule target, String instvarsuf, Object instconfig)
            throws Exception
    {
        OpndLhs[] paramwires = new OpndLhs[params.length];
        for (int i = 0; i < params.length; i ++) {
            OpndLhs oldparam  = params[i];
            OpndLhs paramwire = new OpndLhs ();
            paramwire.name    = oldparam.name + instvarsuf;
            paramwire.lodim   = oldparam.lodim;
            paramwire.hidim   = oldparam.hidim;
            paramwires[i]     = paramwire;
            assert target.variables.get (paramwire.name) == null;
            target.variables.put (paramwire.name, paramwire);
        }
        return paramwires;
    }
}
