# instruction register
#  input:
#    MQ = instruction from memory
#    WE = load register at end of cycle
module insreg (out Q[15:00], out _Q[15:00], in MQ[15:00], in _WE)
{
    wire g_a, g_b, g_c, g_d;

    # WE is direct output of state flipflop so just use a latch
    # WE drops at end of FETCH_2 and so holds the data

    g_a = ~_WE;
    g_b = ~_WE;
    g_c = ~_WE;
    g_d = ~_WE;

    ir1512: DLat 4 (Q:Q[15:12], _Q:_Q[15:12], D:MQ[15:12], G:g_a);
    ir1108: DLat 4 (Q:Q[11:08], _Q:_Q[11:08], D:MQ[11:08], G:g_b);
    ir0704: DLat 4 (Q:Q[07:04], _Q:_Q[07:04], D:MQ[07:04], G:g_c);
    ir0300: DLat 4 (Q:Q[03:00], _Q:_Q[03:00], D:MQ[03:00], G:g_d);
}
