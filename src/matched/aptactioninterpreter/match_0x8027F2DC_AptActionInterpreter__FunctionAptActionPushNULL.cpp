// 0x8027F2DC AptActionInterpreter::_FunctionAptActionPushNULL (100B)
// Push g_aptActionGlobal onto operand stack, increment sp, then MI-vcall
// with opcode 138 + two abs-addr string constants (file:line debug info).
// Session 12 Track C middle-pool pioneer — Techniques #57/#58/#59.

typedef unsigned char u8;

extern u8* g_aptActionGlobal;       // SDA r13-22936
extern char g_aptDbgStr1680[16];    // abs 0x80401680 (non-SDA)
extern char g_aptDbgStr16B4[16];    // abs 0x804016B4 (non-SDA)

struct AptActionInterpreter {
    int m_stackIdx;    // 0x00
    char pad_04[4];
    u8** m_stack;      // 0x08

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPushNULL(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushNULL(
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
