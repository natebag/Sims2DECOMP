// 0x8027F62C AptActionInterpreter::_FunctionAptActionPushGlobalVariable (100B)
// A-family (Push-simple) variant — reads g_aptGlobalVar SDA at r13-27508
// instead of g_aptActionGlobal. Structure identical to PushNULL.
// Validates Sub-family A template with different-SDA-singleton scope.

typedef unsigned char u8;

extern u8* g_aptGlobalVar;          // SDA r13-27508
extern char g_aptDbgStr1680[16];
extern char g_aptDbgStr16B4[16];

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPushGlobalVariable(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushGlobalVariable(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int sp asm("r9") = interp->m_stackIdx;
    register u8* val asm("r10") = g_aptGlobalVar;
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
