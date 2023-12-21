MType MMath(exp) (MType x)
{
    if (! MMath(isfinite) (x)) {
        if (MMath(isnan) (x)) return MNAN;
        return (x < 0.0) ? 0.0 : MINF;
    }

    if (x == 0.0) return 1.0;
    if (x < 0.0) {
        return 1.0 / MMath (exp) (- x);
    }

    MType n  = x;
    MType f  = 1.0;
    MType y  = x + 1.0;
    MType y1 = y;
    MType y2 = y;
    while (1) {
        n *= x / ++ f;
        y += n;
        if ((y == y1) || (y == y2)) return y;
        y2 = y1;
        y1 = y;
    }
}

