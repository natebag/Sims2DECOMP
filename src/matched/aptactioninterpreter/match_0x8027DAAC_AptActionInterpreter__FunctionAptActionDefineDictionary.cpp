// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8027DAAC AptActionInterpreter::_FunctionAptActionDefineDictionary (40B)
// Leaf handler: read 4-aligned 8B arg from bytecode, advance pc+8,
// store two words into interp->m_dict{Ptr,Len}.
// Session 12 Track C pioneer-3 — Techniques #53/#54/#55.

struct AptActionInterpreter {
    char pad_00[0x34];
    int m_dictPtr;   // 0x34
    int m_dictLen;   // 0x38

    struct LocalContextT {
        int* m_pc;   // 0x00
    };

    static void _FunctionAptActionDefineDictionary(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionDefineDictionary(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int* pc asm("r11") = ctx->m_pc;
    pc = (int*)(((unsigned int)pc + 3) & ~3u);
    ctx->m_pc = (int*)((char*)pc + 8);
    register int w0 asm("r9") = pc[0];
    register int w1 asm("r10") = pc[1];
    interp->m_dictPtr = w0;
    interp->m_dictLen = w1;
}
