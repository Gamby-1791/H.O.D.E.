void putstr (char const *str);
void putptr (void *ptr);

struct P1 {
    int p1;
    virtual void f1 ();
};

struct P2 {
    int p2;
    virtual void f2 ();
};

struct Ch : P1, P2 {
    Ch ();
    virtual ~Ch ();
    int ch;
    virtual void fc ();
    virtual void f1 ();
    virtual void f2 ();
};

void test23 (P1 *p1, P2 *p2, Ch *ch)
{
    p1->f1 ();
    p2->f2 ();
    ch->fc ();
    ch->f1 ();
    ch->f2 ();

    char *buf = new char[p2->p2];
    putptr (buf);

    Ch *challoc = new Ch;
    putptr (challoc);

    Ch stackch;
    putptr (&stackch);
}

Ch::Ch ()
{
    putstr ("constructing a Ch\n");
    putptr (this);
}

Ch::~Ch ()
{
    putstr ("destructing a Ch\n");
}

void Ch::fc ()
{
    putstr ("this is Ch::fc\n");
}

void Ch::f1 ()
{
    putstr ("this is Ch::f1\n");
}

void P1::f1 ()
{
    putstr ("this is P1::f1\n");
}
