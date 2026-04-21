// 0x8027F340 AptActionInterpreter::_FunctionAptActionPushUndefined (100B)
// Byte-identical to PushNULL body — A-family (Push-simple) sibling clone.
// Validates Sub-family A template from apt-opcode-middle-template.md.

typedef unsigned char u8;

extern u8* g_aptActionGlobal;
extern char g_aptDbgStr1680[16];
extern char g_aptDbgStr16B4[16];

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPushUndefined(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushUndefined(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int sp asm("r9") = interp->m_stackIdx;
    register u8* val asm("r10") = g_aptActionGlobal;
    register u8** stack asm("r8") = interp->m_stack;
    register int sp4 asm("r11") = sp << 2;
    sp = sp + 1;
    register int stackInt asm("r8") = (int)stack;
    *(u8**)(sp4 + stackInt) = val;
    interp->m_stackIdx = sp;
    char* vt = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
