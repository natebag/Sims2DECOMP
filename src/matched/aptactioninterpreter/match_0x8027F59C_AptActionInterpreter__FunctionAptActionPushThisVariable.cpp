// 0x8027F59C AptActionInterpreter::_FunctionAptActionPushThisVariable (144B)
// Sub-family E: Accessor-call-then-push. Calls inner helper with ctx+consts,
// pushes result onto stack, standard MI-vcall tail.
// Session 12 Track C middle-pool sub-family E pioneer — Technique #60.

typedef unsigned char u8;

extern u8* AptActionInterpreter_GetThisVariable(
    void* interp, void* ctxA, void* ctxB, void* absPtr,
    int flag1, int flag2, int flag3);

extern char g_aptDbgStr1680[16];
extern char g_aptDbgStr16B4[16];

// absolute constant at section base + offset 656 (lis -32694 + -11332 + 656).
// Technique #60: split address via r6-pin + separate addi to prevent
// GCC folding the 2 addis that SN emits (section base + field offset).
extern char g_aptXxx_section[];

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT {
        int* m_pc;          // 0x00
        void* m_ctxA;       // 0x04
        void* m_ctxB;       // 0x08
    };

    static void _FunctionAptActionPushThisVariable(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushThisVariable(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    void* ctxB = ctx->m_ctxB;
    void* ctxA = ctx->m_ctxA;
    register char* base asm("r6") = g_aptXxx_section;
    void* field = (void*)((char*)base + 656);
    u8* val = AptActionInterpreter_GetThisVariable(
        interp, ctxA, ctxB, field, 1, 1, 0);
    register int sp asm("r9") = interp->m_stackIdx;
    register int stackInt asm("r10") = (int)interp->m_stack;
    register int sp4 asm("r11") = sp << 2;
    sp = sp + 1;
    *(u8**)(sp4 + stackInt) = val;
    interp->m_stackIdx = sp;
    char* vt = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
