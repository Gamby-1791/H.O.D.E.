// returns -PI/2..+PI/2
MType MMath(asin) (MType x)
{
    if (MMath(isnan) (x) || (x < -1.0) || (x > 1.0)) return MNAN;
    MType xx = x * x;
    MType i  = 1.0;
    MType y  = x;
    MType y1 = y;
    MType y2 = y;
    while (1) {
        x *= i;
        x /= ++ i;
        x *= xx;
        y += x / (++ i);
        if ((y == y1) || (y == y2)) return y;
        y2 = y1;
        y1 = y;
    }
}

