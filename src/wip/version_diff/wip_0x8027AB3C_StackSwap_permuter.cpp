// PERMUTER CANDIDATE — Sub-family F (Stack-pop-push-no-vcall).
// 0x8027AB3C AptActionInterpreter::_FunctionAptActionStackSwap (112B)
// Session 12 Track C middle-pool sub-family F pioneer (PARTIAL match).
//
// STATE: ~90% byte match with 3 instruction-pair swaps:
//   offset 0x38/0x3c — register choice for spMinus2 (r0 vs r8) for
//                       `addi _,r8,-1; stw _,0(r3)`
//   offset 0x54/0x5c — interp.sp store vs stack reload ordering
//   offset 0x60/0x64 — addi r9 (sp+2) vs stwx (store) ordering
//
// All swaps are semantics-neutral adjacent-instruction reorderings.
// Asm-processor permuter candidate.
//
// Total permuter queue now: 9 candidates
//   2 Manipulator (GetAffectedWallHeight, CheckCancelTimer)
//   6 SonnetWorker2's 338-batch walls (per MainGuy)
//   1 D-family (PushStringDictByte)
//   1 F-family (this)
//
// Crosses S13 asm-processor infrastructure priority threshold.

typedef unsigned char u8;

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionStackSwap(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStackSwap(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int sp asm("r10") = interp->m_stackIdx;
    register int stackInt asm("r0") = (int)interp->m_stack;
    register int spMinus1 asm("r8") = sp - 1;
    register int sp4 asm("r9") = sp << 2;
    register int sp4m1 asm("r11") = spMinus1 << 2;
    register u8* v1 asm("r7") = *(u8**)(sp4 + stackInt - 4);
    register u8* v2 asm("r6") = *(u8**)(sp4m1 + stackInt - 4);
    if (sp > 0) {
        interp->m_stackIdx = spMinus1;
        if (spMinus1 > 0) {
            interp->m_stackIdx = spMinus1 - 1;
        }
    }
    register int sp2 asm("r9") = interp->m_stackIdx;
    register int stack2 asm("r10") = (int)interp->m_stack;
    register int sp2_4 asm("r11") = sp2 << 2;
    *(u8**)(sp2_4 + stack2) = v1;
    sp2 = sp2 + 1;
    interp->m_stackIdx = sp2;
    register int sp2_4b asm("r10") = sp2 << 2;
    register int stack3 asm("r11") = (int)interp->m_stack;
    sp2 = sp2 + 1;
    *(u8**)(sp2_4b + stack3) = v2;
    interp->m_stackIdx = sp2;
}
