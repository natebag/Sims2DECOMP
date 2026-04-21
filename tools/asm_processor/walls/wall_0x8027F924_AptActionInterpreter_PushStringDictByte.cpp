// asm-processor input: 0x8027F924 AptActionInterpreter::_FunctionAptActionPushStringDictByte (128B).
//
// Original src/wip/version_diff draft used `register T asm("rN")` pins
// on every local — Family-B fake per verify_match.sh. This is the
// banned-pin-free rewrite. Semantics recap:
//   byte = *pc++  (advance pc in ctx)
//   val  = dict[byte << 2]  (dict at interp+0x38)
//   stack[sp++] = val
//   mi-vcall opcode 138 on *val with two debug strings

typedef unsigned char u8;

extern char g_aptDbgStr1680[16];      // 0x80401680
extern char g_aptDbgStr16B4[16];      // 0x804016B4

struct AptActionInterpreter {
    int m_stackIdx;    // 0x00
    char pad_04[4];
    u8** m_stack;      // 0x08
    char pad_0C[0x2C];
    u8** m_dict;       // 0x38

    struct LocalContextT { u8* m_pc; };

    static void _FunctionAptActionPushStringDictByte(AptActionInterpreter* interp,
                                                      LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushStringDictByte(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    u8* pc = ctx->m_pc;
    unsigned int byte = (unsigned int)*pc;
    pc = pc + 1;
    ctx->m_pc = pc;
    byte = byte << 2;

    int dictInt = *(int*)((char*)interp + 56);
    u8* val = *(u8**)(byte + dictInt);

    int sp = interp->m_stackIdx;
    u8** stack = interp->m_stack;
    stack[sp] = val;
    interp->m_stackIdx = sp + 1;

    char* vt = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
