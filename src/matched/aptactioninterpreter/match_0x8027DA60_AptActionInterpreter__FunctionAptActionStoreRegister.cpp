// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8027DA60 AptActionInterpreter::_FunctionAptActionStoreRegister (76B)
// Read reg-index arg from bytecode, pop-top AptValue*, call SetRegisterValue.
// Session 12 Track C pioneer-3 — Techniques #53/#54/#55.

struct AptValue;
extern void AptScriptFunctionBase_SetRegisterValue(int regIdx, AptValue* val);

struct AptActionInterpreter {
    int m_stackIdx;       // 0x00
    char pad_04[4];
    AptValue** m_stack;   // 0x08

    struct LocalContextT {
        int* m_pc;        // 0x00
    };

    static void _FunctionAptActionStoreRegister(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStoreRegister(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int* pc asm("r11") = ctx->m_pc;
    pc = (int*)(((unsigned int)pc + 3) & ~3u);
    ctx->m_pc = (int*)((char*)pc + 4);
    register int sp asm("r9") = interp->m_stackIdx;
    register int stack asm("r0") = *(int*)((char*)interp + 8);
    sp = sp * 4;
    register int regIdx asm("r3") = pc[0];
    sp = sp + stack;
    AptValue* val = *(AptValue**)(sp - 4);
    AptScriptFunctionBase_SetRegisterValue(regIdx, val);
}
