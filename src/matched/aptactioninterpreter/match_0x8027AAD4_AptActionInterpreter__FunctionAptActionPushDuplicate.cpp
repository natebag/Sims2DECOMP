// 0x8027AAD4 AptActionInterpreter::_FunctionAptActionPushDuplicate (104B)
// Duplicate top of stack — read stack[sp-1] and push as new stack[sp].
// Then MI-vcall with opcode 138 (same vt slot as PushNULL).
// Session 12 Track C middle-pool pioneer — Techniques #57/#58/#59.

typedef unsigned char u8;

extern char g_aptDbgStr1680[16];    // abs 0x80401680
extern char g_aptDbgStr16B4[16];    // abs 0x804016B4

struct AptActionInterpreter {
    int m_stackIdx;    // 0x00
    char pad_04[4];
    u8** m_stack;      // 0x08

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPushDuplicate(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushDuplicate(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register int sp asm("r10") = interp->m_stackIdx;
    register int stackInt asm("r7") = (int)interp->m_stack;
    register int sp4 asm("r8") = sp << 2;
    register u8* val asm("r11") = *(u8**)(sp4 + stackInt - 4);
    sp = sp + 1;
    *(u8**)(sp4 + stackInt) = val;
    interp->m_stackIdx = sp;
    char* vt = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
