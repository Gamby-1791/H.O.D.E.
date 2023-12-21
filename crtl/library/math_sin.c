MType MMath(sin) (MType x)
{
    if (! MMath(isfinite) (x)) return MNAN;
    while (x < -MPI) x += MPI * 2.0;
    while (x >= MPI) x -= MPI * 2.0;
    MType mxx = - x * x;
    MType m   = 1.0;
    MType y   = x;
    MType y1  = x;
    MType y2  = x;
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

