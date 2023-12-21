/**
 * One of these per module, builtin or user defined.
 */

import java.io.PrintStream;
import java.util.HashMap;
import java.util.LinkedList;

public abstract class Module {
    public LinkedList<ConnModule> connectors;   // connectors in this module (make sure they get placed on pcb)
    public OpndLhs[] params;                    // parameters
    public HashMap<String,OpndLhs> variables;   // variables (parameters, wires)
    public LinkedList<OpndLhs> generators;      // also generate these elements as well as output parameters
    public String name;                         // module name

    public Module ()
    {
        generators = new LinkedList<> ();
        variables  = new HashMap<> ();
        connectors = new LinkedList<> ();
    }

    // this can get tokens after the module name and before the (
    // eg, inst : DFF 16 ( ... );
    //                ^ token is here
    //                   ^ return token here
    // source-defined modules do not have any config tokens
    public Token getInstConfig (Token token, String instvarsuf, Object[] instconfig_r)
            throws Exception
    {
        return token;
    }

    // make an array of wires corresponding to instantiated module and insert into target module
    // caller can then use them in assignment-like constructs to match with arguments
    public abstract OpndLhs[] getInstParams (UserModule target, String instvarsuf, Object instconfig)
            throws Exception;

    // get whether module parameter is an 'input' or an 'output' parameter
    //  input:
    //   instconfig = as returned by getInstConfig()
    //   prmn = parameter number
    //  output:
    //   returns true: IN
    //          false: OC,OUT
    public boolean isInstParamIn (Object instconfig, int prmn)
    {
        OpndLhs param = params[prmn];
        assert param instanceof IParam || param instanceof OParam;
        return param instanceof IParam;
    }
}
