// returns -PI/2..+PI/2
MType MMath(atan) (MType x)
{
    if (MMath(isnan) (x)) return x;
    if (x == 0.0) return x;
    if (x < 0.0) return - MMath(atan) (- x);
    if (MMath(isinf) (x)) return MPI / 2.0;
    if (x > 1.0) return MPI / 2.0 - MMath(atan) (1.0 / x);
    if (x == 1.0) return MPI / 4.0;

    // y = x - x**3/3 + x**5/5 - x**7/7 + x**9/9 ...
    MType mxx = - x * x;
    MType d   = 1.0;
    MType y1  = x;
    MType y2  = x;
    while (1) {
        x *= mxx;
        d += 2.0;
        MType y = y1 + x / d;
        if ((y == y1) || (y == y2)) return y;
        y2 = y1;
        y1 = y;
    }
}

