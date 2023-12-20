#include <stdlib.h>

#include "mytypes.h"
#include "opcode.h"

char const *opcodestr (Opcode opcode)
{
    switch (opcode) {
        case OP_COMMA:   return ",";
        case OP_MOVE:    return "=";

        case OP_COLON:   return ":";
        case OP_QMARK:   return "?";
        case OP_ASNEQ:   return "=";
        case OP_ASNADD:  return "+=";
        case OP_ASNSUB:  return "-=";
        case OP_ASNMUL:  return "*=";
        case OP_ASNDIV:  return "/=";
        case OP_ASNMOD:  return "%=";
        case OP_ASNSHL:  return "<<=";
        case OP_ASNSHR:  return ">>=";
        case OP_ASNAND:  return "&=";
        case OP_ASNXOR:  return "^=";
        case OP_ASNOR:   return "|=";

        case OP_LOGOR:   return "||";
        case OP_LOGAND:  return "&&";
        case OP_BITOR:   return "|";
        case OP_BITXOR:  return "^";
        case OP_BITAND:  return "&";

        case OP_CMPEQ:   return "==";
        case OP_CMPNE:   return "!=";

        case OP_CMPGE:   return ">=";
        case OP_CMPGT:   return ">";
        case OP_CMPLE:   return "<=";
        case OP_CMPLT:   return "<";

        case OP_SHL:     return "<<";
        case OP_SHR:     return ">>";

        case OP_ADD:     return "+";
        case OP_SUB:     return "-";

        case OP_DIV:     return "/";
        case OP_MUL:     return "*";
        case OP_MOD:     return "%";

        case OP_PREINC:  return "++";
        case OP_PREDEC:  return "--";
        case OP_NEGATE:  return "-";
        case OP_LOGNOT:  return "!";
        case OP_BITNOT:  return "~";
        case OP_DEREF:   return "*";
        case OP_ADDROF:  return "&";
        case OP_SIZEOF:  return "sizeof";
        case OP_ALIGNOF: return "alignof";

        case OP_POSTINC: return "++";
        case OP_POSTDEC: return "--";
        case OP_FUNCALL: return "(...)";
        case OP_SUBSCR:  return "[...]";
        case OP_MEMDOT:  return ".";
        case OP_MEMPTR:  return "->";

        default: assert_false ();
    }
}
