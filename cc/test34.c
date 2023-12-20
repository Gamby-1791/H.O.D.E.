void putstr (char const *str);

struct BaseClass {
    int basevar;
    virtual ~BaseClass ();
};

struct Struct : BaseClass {
    double somevar;
    int anothervar;

    virtual ~Struct ();
};

BaseClass::~BaseClass ()
{
    putstr ("I`m dead!");
}

Struct::~Struct ()
{
    putstr ("I'm dying!");
}

void test34 ()
{
    Struct *s = new Struct;
    BaseClass *b = s;
    delete b;

    Struct *a = new Struct[2];
    delete[] a;
}
