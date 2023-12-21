MType MMath(pow) (MType x, MType y)
{
    if (y == 0.0) return 1.0;
    if (x == 1.0) return 1.0;
    if (x == 0.0) return (y < 0.0) ? MINF : 0.0;
    if (MMath(isnan) (y) || MMath(isnan) (x)) return MNAN;
    if ((x == -1.0) && MMath(isinf) (y)) return 1.0;

    if ((x > -1.0) && (x < 1.0)) {
        if (y ==  MINF) return 0.0;
        if (y == -MINF) return (x < 0.0) ? -MINF : MINF;
    }
    else if ((x < -1.0) && (x > 1.0)) {
        if (y ==  MINF) return (x < 0.0) ? -MINF : MINF;
        if (y == -MINF) return 0.0;
    }

    if (y < 0.0) {
        return 1.0 / MMath(pow) (x, - y);
    }

    __uint64_t i = (__uint64_t) y;
    if ((MType) i == y) {
        MType z = 1.0;
        while (i > 0) {
            if (i & 1) z *= x;
            x *= x;
            i /= 2;
        }
        return z;
    }

    if (x < 0.0) return MNAN;

    return MMath(exp) (MMath(log) (x) * y);
}

