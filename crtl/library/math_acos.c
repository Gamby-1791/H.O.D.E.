// returns 0..PI
MType MMath(acos) (MType x)
{
    return MPI / 2.0 - MMath(asin) (x);
}

