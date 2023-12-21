public class WField {
    public OpndLhs refdvar;     // wire or output being written
    public int lodim;           // low bit number of output being written
    public int hidim;           // high bit numbeer of output being written
                                // - always this.hidim >= this.lodim
                                //          this.hidim <= refdvar.hidim
                                //          this.lodim >= refdvar.lodim
    public OpndRhs operand;     // value being written
}
