module dffminiflat (in d, in t, out _q, out q)
{
    thedff: DFF miniflat (D:d, T:t, _Q:_q, Q:q, _PC:1, _PS:1);
}
