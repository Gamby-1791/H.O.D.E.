MType MMath(log) (MType x)
{
    if (MMath (isnan) (x) || (x < 0.0)) return MNAN;
    if (MMath (isinf) (x)) return MINF;
    if (x == 0.0) return - MINF;
    if (x == 1.0) return 0.0;

    int exp;
    x = MMath (frexp) (x, &exp);

    MType u  = x - 1.0;
    MType mu = - u;
    MType d  = 1.0;
    MType y  = u;
    MType y1 = u;
    MType y2 = u;
    while (1) {
        u *= mu;
        y += u / ++ d;
        if ((y == y1) || (y == y2)) return y + exp / (MType) M_LOG2E;
        y2 = y1;
        y1 = y;
    }
}
