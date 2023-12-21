public class ReduceEx extends Exception {
    public Token token;
    public String message;
    public ReduceEx (Token tok, String msg)
    {
        token = tok;
        message = msg;
    }
}
