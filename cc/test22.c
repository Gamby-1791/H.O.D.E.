typedef __uint16_t LineNum;

void ass_putint (int i);

struct Value { };

struct IntValue : Value {
    int value;
};

struct StrValue : Value {
    char const *value;
};

struct Expr {
    LineNum explinum;
    virtual Value *compute ();
};

struct Label {
    LineNum lablinum;
};

struct Stmt {
    LineNum linenum;
    virtual Stmt *execute ();
};

struct IfStmt : Stmt {
    Expr *condexpr;
    Label *thenlabel;
};


void test22 ()
{
    IfStmt ifstmt;

    ass_putint ((__size_t) &ifstmt.linenum   - (__size_t) &ifstmt);
    ass_putint ((__size_t) &ifstmt.condexpr  - (__size_t) &ifstmt);
    ass_putint ((__size_t) &ifstmt.thenlabel - (__size_t) &ifstmt);
}
