// PERMUTER CANDIDATE — String-family pc-reading dict-lookup sub-family.
// 0x8027F924 AptActionInterpreter::_FunctionAptActionPushStringDictByte (128B)
// Session 12 Track C middle-pool sub-family D pioneer (PARTIAL match).
//
// STATE: ~75-90% byte match with 3 instruction-pair swaps at offsets
// 0x38/0x3c, 0x40/0x44, 0x4c/0x50. GCC vs SN ProDG scheduler disagree
// on:
//   (a) dict-load (lwz r10,56(r3)) vs sp-load (lwz r9,0(r3)) order
//   (b) lwzx val (val=dict[byte4]) vs stack-load (lwz r7,8(r3)) order
//   (c) addi r9,r9,1 (sp+1) vs stwx (store-to-stack) order
//
// All 3 swaps are semantics-neutral instruction pairs. Permuter
// candidate. Dual-scheduler-off flags cause SIZE_MISMATCH (grows),
// default scheduling produces the listed diffs.
//
// Not committed to src/matched/ — would fail pre-commit byte check.
// Move here pending asm-processor permuter landing.
//
// Original body:
// pc-reading dict-lookup sub-family: read 1B from bytecode, look up in
// interp->m_dict (offset 0x38), push onto stack, MI-vcall opcode 138.

typedef unsigned char u8;

extern char g_aptDbgStr1680[16];    // abs 0x80401680
extern char g_aptDbgStr16B4[16];    // abs 0x804016B4

struct AptActionInterpreter {
    int m_stackIdx;    // 0x00
    char pad_04[4];
    u8** m_stack;      // 0x08
    char pad_0C[0x2C];
    u8** m_dict;       // 0x38

    struct LocalContextT { u8* m_pc; };

    static void _FunctionAptActionPushStringDictByte(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPushStringDictByte(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register LocalContextT* c asm("r10") = ctx;
    register u8* pc asm("r9") = c->m_pc;
    register unsigned int byte asm("r11") = (unsigned int)*pc;
    pc = pc + 1;
    c->m_pc = pc;
    byte = byte << 2;
    register int dictInt asm("r10") = *(int*)((char*)interp + 56);
    register u8* val asm("r8") = *(u8**)(byte + dictInt);
    register int sp asm("r9") = interp->m_stackIdx;
    register int stackInt asm("r7") = (int)interp->m_stack;
    register int sp4 asm("r11") = sp << 2;
    sp = sp + 1;
    *(u8**)(sp4 + stackInt) = val;
    interp->m_stackIdx = sp;
    register char* vt asm("r11") = *(char**)((char*)val + 8);
    short thisOff = *(short*)(vt + 8);
    void (*fn)(void*, char*, char*, int) =
        *(void(**)(void*, char*, char*, int))(vt + 12);
    fn((char*)val + thisOff, g_aptDbgStr1680, g_aptDbgStr16B4, 138);
}
