// 0x8027AB3C AptActionInterpreter::_FunctionAptActionStackSwap (112B)
//
// Cracked S13 Lane E E-15 (2026-05-02) via FIRST multi-directive composition
// test in the asm_processor. Uses 11 directives in source order combining
// 4 mutator types (swap_adj, swap_operands, force_reg ×7, swap_operands)
// to walk the natural-source GCC compile to byte-exact DOL match.
//
// Composition validated:
//   1. swap_adj fixes the 0x010-0x014 instruction-pair reorder
//   2. swap_operands transposes commutative add operand positions
//   3. force_reg ×N walks per-line register coloring to DOL's choices
//   4. Each pass operates on the cumulative .s text from prior passes,
//      so anchor strings reflect POST-MUTATION state
//
// Key implementation insight: directives.py needed shlex tokenization
// to support quoted match values ("add 9,11,9") since cc1plus emits
// space-bearing operand strings.

// ASMPROC_swap_adj: a=add b=slwi which=first
// ASMPROC_swap_operands: match="add 9,11,9" pos=1,2
// ASMPROC_force_reg: match="add 9,9,11" from_reg=11 to_reg=0
// ASMPROC_force_reg: match="slwi 0,8,2" from_reg=0 to_reg=11
// ASMPROC_force_reg: match="lwz 11,8(3)" from_reg=11 to_reg=0 occurrence=0
// ASMPROC_force_reg: match="lwz 11,8(3)" from_reg=11 to_reg=10 occurrence=0
// ASMPROC_force_reg: match="slwi 0,9,2" from_reg=0 to_reg=11 occurrence=0
// ASMPROC_force_reg: match="stwx 7,11,0" from_reg=0 to_reg=10
// ASMPROC_force_reg: match="slwi 0,9,2" from_reg=0 to_reg=10 occurrence=0
// ASMPROC_swap_operands: match="stwx 6,11,0" pos=1,2
// ASMPROC_force_reg: match="stwx 6,0,11" from_reg=0 to_reg=10

typedef unsigned char u8;

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

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
