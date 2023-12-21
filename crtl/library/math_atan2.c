// returns -PI..+PI
MType MMath(atan2) (MType y, MType x)
{
    if (MMath(isnan) (y) || MMath(isnan) (x)) return MNAN;
    if (x == 0.0) {
        if (y == 0.0) return 0.0;
        if (y < 0.0) return - MPI / 2.0;
        return MPI / 2.0;
    }
    MType theta = MMath(atan) (y / x);
    if (MMath(isnan) (theta)) return theta;
    if (x >= 0.0) return theta;
    return (y >= 0.0) ? theta + MPI : theta - MPI;
}

