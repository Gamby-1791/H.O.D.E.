struct CType {
    CData real;
    CData imag;

    static CType make (CData r, CData i);

    CType add (CType x);
    CType sub (CType x);
    CType mul (CType x);
    CType div (CType x);
    CType par (CType x);
    CType mulr (CData x);
    CType divr (CData x);
    CType neg ();
    CType rec ();
    CData abs ();
    CData arg ();
    CType sq  ();

    void addeq (CType x);
    void subeq (CType x);
    void muleq (CType x);
    void diveq (CType x);

    CType pow (CType x);
    CType acos ();
    CType asin ();
    CType atan ();
    CType cos ();
    CType exp ();
    CType log ();
    CType sin ();
    CType sqrt ();
    CType tan ();
};
