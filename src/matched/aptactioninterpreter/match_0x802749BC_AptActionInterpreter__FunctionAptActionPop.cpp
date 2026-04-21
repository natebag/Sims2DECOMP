// 0x802749BC AptActionInterpreter::_FunctionAptActionPop (164B)
// C-family 2nd pioneer (vt+16/+20 MI-vcall) + secondary ReleaseValues.
// Validates C-family dispatch offsets across 2 samples (was single-sample
// via StopDragMovie). Unlocks C-family Kimi blast scope.
// Session 12 Track C middle-pool — technique repertoire #58 + #55.

typedef unsigned char u8;

extern u8* g_aptValueVector;   // SDA r13-27600
extern void AptValueVector_ReleaseValues(u8* self);

extern char g_popDbgStr_174C[16];   // abs 0x8040174C
extern char g_popDbgStr_16B4[16];   // abs 0x804016B4

struct AptActionInterpreter {
    int m_stackIdx;         // 0x00
    char pad_04[4];
    u8** m_stack;            // 0x08
    char pad_0C[0x4C];
    int m_stackLimit;        // 0x58

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionPop(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionPop(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    int sp = interp->m_stackIdx;
    if (sp > interp->m_stackLimit && sp > 0) {
        u8** stack = interp->m_stack;
        u8* top = *(u8**)((char*)stack + sp * 4 - 4);
        char* vt = *(char**)((char*)top + 8);
        short thisOff = *(short*)(vt + 16);
        void (*fn)(void*, char*, char*, int) =
            *(void(**)(void*, char*, char*, int))(vt + 20);
        fn((char*)top + thisOff, g_popDbgStr_174C, g_popDbgStr_16B4, 160);
        interp->m_stackIdx = interp->m_stackIdx - 1;
    }
    if (sp == 1) {
        u8* vec = g_aptValueVector;
        if (*(int*)((char*)vec + 4) != 0) {
            AptValueVector_ReleaseValues(vec);
        }
    }
}
