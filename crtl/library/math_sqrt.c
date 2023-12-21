MType MMath(sqrt) (MType x)
{
    if (x == 0.0) return 0.0;
    if (x < 0.0) return MNAN;
    if (! MMath(isfinite) (x)) return x;

    MType y1, y2;
    if (sizeof x == 4) {
        union { MType f; __uint16_t u[2]; } v;
        v.f = x;
        v.u[1] = (v.u[1] & 0x007FU) | ((v.u[1] & 0x7F00U) / 2 +  (64 << 7));
        y1 = y2 = v.f;
    }
    if (sizeof x == 8) {
        union { MType f; __uint16_t u[4]; } v;
        v.f = x;
        v.u[3] = (v.u[3] & 0x000FU) | ((v.u[3] & 0x7FE0U) / 2 + (512 << 4));
        y1 = y2 = v.f;
    }

    while (1) {
        MType y = (x / y1 + y1) / 2.0;
        if ((y == y1) || (y == y2)) return y;
        y2 = y1;
        y1 = y;
    }
}

