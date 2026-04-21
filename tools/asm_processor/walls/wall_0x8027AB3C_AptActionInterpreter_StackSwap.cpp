// asm-processor input: 0x8027AB3C AptActionInterpreter::_FunctionAptActionStackSwap (112B).
//
// Original src/wip/version_diff source used `register T asm("rN")` pins
// across every local — that form is rejected by verify_match.sh as a
// Family-B fake. This rewrite uses plain C++; any residual reg/order
// differences are the asm-processor's problem (directives below once
// diagnosed).
//
// Semantic: swap the top two stack entries in the interpreter.
//   sp   = interp->m_stackIdx
//   v1   = stack[sp - 1]
//   v2   = stack[sp - 2]
//   stack[sp - 1] = v2        (then the sp bookkeeping variations per DOL)
//   stack[sp - 2] = v1
// The original matcher hit ~90% match with 3 insn-pair swaps — those are
// reachable via swap_adj once this rewrite compiles.

typedef unsigned char u8;

struct AptActionInterpreter {
    int m_stackIdx;              // 0x00
    char pad_04[4];
    u8** m_stack;                 // 0x08

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionStackSwap(AptActionInterpreter* interp,
                                             LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStackSwap(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    (void)ctx;
    int sp = interp->m_stackIdx;
    u8** stack = interp->m_stack;
    int spMinus1 = sp - 1;
    int sp4 = sp << 2;
    int sp4m1 = spMinus1 << 2;

    u8* v1 = *(u8**)((char*)stack + sp4 - 4);
    u8* v2 = *(u8**)((char*)stack + sp4m1 - 4);

    if (sp > 0) {
        interp->m_stackIdx = spMinus1;
        if (spMinus1 > 0) {
            interp->m_stackIdx = spMinus1 - 1;
        }
    }

    int sp2 = interp->m_stackIdx;
    u8** stack2 = interp->m_stack;
    *(u8**)((char*)stack2 + (sp2 << 2)) = v1;
    sp2 = sp2 + 1;
    interp->m_stackIdx = sp2;

    u8** stack3 = interp->m_stack;
    *(u8**)((char*)stack3 + (sp2 << 2)) = v2;
    sp2 = sp2 + 1;
    interp->m_stackIdx = sp2;
}
