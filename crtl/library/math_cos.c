MType MMath(cos) (MType x)
{
    if (! MMath(isfinite) (x)) return MNAN;
    if (x < 0.0) x = -x;
    while (x >= MPI) x -= MPI * 2.0;
    MType mxx = - x * x;
    MType m   = 0.0;
    MType y   = 1.0;
    MType y1  = 1.0;
    MType y2  = 1.0;
    x = 1.0;
    while (1) {
        x *= mxx;
        x /= ++ m;
        x /= ++ m;
        y += x;
        if ((y == y1) || (y == y2)) return y;
        y2 = y1;
        y1 = y;
    }
}

