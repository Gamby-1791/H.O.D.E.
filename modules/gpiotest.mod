module gpiotest (out md[15:00], out mword, out mread, out mwrite, out halt,
        in clk, in irq, in res, in mq[15:00], in dena, in qena)
{
    gpiomod: GPIO (MD:md, MWORD:mword, MREAD:mread, MWRITE:mwrite, HALT:halt,
        CLK:clk, IRQ:irq, RES:res, MQ:mq, DENA:dena, QENA:qena);
}
