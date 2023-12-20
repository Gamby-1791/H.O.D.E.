#ifndef _LOCN_H
#define _LOCN_H

struct Locn;
struct CalarLocn;
struct LabelLocn;
struct ParamLocn;
struct RBRPtLocn;
struct StackLocn;

#include "decl.h"
#include "mach.h"
#include "mytypes.h"

enum LocnType {
    LT_CALAR,
    LT_LABEL,
    LT_PARAM,
    LT_RBRPT,
    LT_STACK
};

struct Locn {
    virtual CalarLocn *castCalarLocn () { return nullptr; }
    virtual LabelLocn *castLabelLocn () { return nullptr; }
    virtual ParamLocn *castParamLocn () { return nullptr; }
    virtual RBRPtLocn *castRBRPtLocn () { return nullptr; }
    virtual StackLocn *castStackLocn () { return nullptr; }

    virtual bool getStkOffs (int16_t *stkoffs_r, tsize_t spoffs) { return false; }

    LocnType locntype;
};

// call argument
struct CalarLocn : Locn {
    CalarLocn (tsize_t offset);

    virtual CalarLocn *castCalarLocn () { return this; }

    virtual bool getStkOffs (int16_t *stkoffs_r, tsize_t spoffs);

    tsize_t offset;     // offset from beginning of call argument list
                        // includes extra 2 for return-by-reference functions
};

// assembly language label
struct LabelLocn : Locn {
    LabelLocn ();

    virtual LabelLocn *castLabelLocn () { return this; }

    char const *label;
};

// function parameter
struct ParamLocn : Locn {
    ParamLocn ();

    virtual ParamLocn *castParamLocn () { return this; }

    virtual bool getStkOffs (int16_t *stkoffs_r, tsize_t spoffs);

    FuncDecl *funcdecl; // function this is a parameter of
    tsize_t offset;     // offset from beginning of parameter list (first one is offset 0)
                        // does not include extra 2 for return-by-reference functions
};

// function return-by-reference pointer
struct RBRPtLocn : Locn {
    RBRPtLocn ();

    virtual RBRPtLocn *castRBRPtLocn () { return this; }

    virtual bool getStkOffs (int16_t *stkoffs_r, tsize_t spoffs);

    FuncDecl *funcdecl; // function this is a parameter of
};

// stack variable (other than function parameters)
struct StackLocn : Locn {
    StackLocn ();

    virtual StackLocn *castStackLocn () { return this; }

    virtual bool getStkOffs (int16_t *stkoffs_r, tsize_t spoffs);

    bool addrtaken;     // address of variable taken
    bool assigned;      // offset has been assigned
    Mach *firstwrite;   // start of active range
    Mach *lastread;     // end of active range
    tsize_t offset;     // offset from stack pointer
};

#endif
