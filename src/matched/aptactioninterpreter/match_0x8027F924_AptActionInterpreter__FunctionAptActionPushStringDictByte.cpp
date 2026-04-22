// 0x8027F924 AptActionInterpreter::_FunctionAptActionPushStringDictByte (128B)
// S12 APT middle-pool D-family pioneer — was parked as scheduler/register-coloring
// wall (3 diff offsets at slwi/stwx).
// S13 Track I wall #5: cracked via 3-pass force_reg pipeline.
//
// SN picks r0 as the scaled-index result; DOL picks r11. Additionally DOL's
// stwx uses (rA=r11, rB=r7) while SN's uses (rA=r7, rB=r0). Three directives
// (applied in order): swap slwi output r0->r11, then swap stwx rA r7->r11,
// then swap stwx rB r0->r7. Semantically identical (stwx is commutative in
// rA/rB), just different register-allocator choices.
//
// ASMPROC_force_reg: match=slwi occurrence=1 from_reg=0 to_reg=11
// ASMPROC_force_reg: match=stwx occurrence=0 from_reg=7 to_reg=11
// ASMPROC_force_reg: match=stwx occurrence=0 from_reg=0 to_reg=7

typedef unsigned char u8;

extern char g_aptDbgStr1680[16];
extern char g_aptDbgStr16B4[16];

struct AptActionInterpreter {
    int m_stackIdx;
    char pad_04[4];
    u8** m_stack;
    char pad_0C[0x2C];
    u8** m_dict;

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
