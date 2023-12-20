void putstr (char const *str);
void putptr (void *ptr);

struct P1 {
    double dbl1;
    int p1;
    virtual void f1 () = 0;
};

struct P2 {
    float flt2;
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

/*void P1::f1 ()
{
    putstr ("this is P1::f1\n");
}*/

Ch staticch;
//P1 staticp1;

Ch *test24 (bool x)
{
    if (x) {
        Ch stackch[7];
        return &stackch[3];
    }

    Ch single;
    return &single;
}
