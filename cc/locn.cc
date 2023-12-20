#include "locn.h"

CalarLocn::CalarLocn (tsize_t offset)
{
    this->locntype = LT_CALAR;
    this->offset   = offset;
}

LabelLocn::LabelLocn ()
{
    locntype = LT_LABEL;
    label    = nullptr;
}

ParamLocn::ParamLocn ()
{
    locntype = LT_PARAM;
    funcdecl = nullptr;
    offset   = 0;
}

RBRPtLocn::RBRPtLocn ()
{
    locntype = LT_RBRPT;
    funcdecl = nullptr;
}

StackLocn::StackLocn ()
{
    locntype   = LT_STACK;
    addrtaken  = false;
    assigned   = false;
    firstwrite = nullptr;
    lastread   = nullptr;
    offset     = 0;
}
