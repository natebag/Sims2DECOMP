// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8027EC04 AptActionInterpreter::_FunctionAptActionBranchAlways (96B)
// Read signed delta, advance pc+4+delta; conditional AptValueVector::ReleaseValues.
// Session 12 Track C pioneer-3 — Techniques #53/#54/#55.

typedef unsigned char u8;

extern u8* g_aptValueVector;   // SDA r13-27600

extern void AptValueVector_ReleaseValues(u8* self);

struct AptActionInterpreter {
    int m_stackIdx;   // 0x00

    struct LocalContextT {
        int* m_pc;    // 0x00
    };

    static void _FunctionAptActionBranchAlways(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionBranchAlways(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int* pc asm("r9") = ctx->m_pc;
    register u8* vec asm("r10") = g_aptValueVector;
    pc = (int*)(((unsigned int)pc + 3) & ~3u);
    register int pcPlus4 asm("r0") = (int)pc + 4;
    ctx->m_pc = (int*)pcPlus4;
    register int delta asm("r11") = pc[0];
    ctx->m_pc = (int*)(pcPlus4 + delta);
    register int dirty asm("r9") = *(int*)(vec + 4);
    if (dirty != 0) {
        if (interp->m_stackIdx == 0) {
            AptValueVector_ReleaseValues(vec);
        }
    }
}
