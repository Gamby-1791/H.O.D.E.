module xor1 (out X, in A, in B)
{
    wire u;
    wire v;
    wire w;
    u = ~(w & A);
    v = ~(w & B);
    w = ~(A & B);
    X = ~(u & v);
}
