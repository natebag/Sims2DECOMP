// 0x80275CB8 AptActionInterpreter::_FunctionAptActionStopDragMovie (100B)
// If global drag-target set: MI-vcall opcode 4686 (vt[16/20]), then clear.
// Uses DIFFERENT vtable offsets (16/20) than Push family (8/12).
// Session 12 Track C middle-pool pioneer — Techniques #57/#58/#59.

typedef unsigned char u8;

extern u8* g_aptActionGlobal;       // SDA r13-22936 (shared with Push family)
extern u8* g_aptDragTarget;         // SDA r13-23008
extern char g_dragDbgStr1CF0[16];   // abs 0x80401CF0
extern char g_dragDbgStr1844[16];   // abs 0x80401844

struct AptActionInterpreter {
    int m_stackIdx;    // 0x00

    struct LocalContextT { int* m_pc; };

    static void _FunctionAptActionStopDragMovie(AptActionInterpreter* interp, LocalContextT* ctx);
};

void AptActionInterpreter::_FunctionAptActionStopDragMovie(
    AptActionInterpreter* interp, LocalContextT* ctx)
{
    register u8* mgr asm("r9") = g_aptDragTarget;
    register u8* drag asm("r11") = *(u8**)((char*)mgr + 60);
    if (drag != 0) {
        char* vt = *(char**)((char*)drag + 8);
        short thisOff = *(short*)(vt + 16);
        void (*fn)(void*, char*, char*, int) =
            *(void(**)(void*, char*, char*, int))(vt + 20);
        fn((char*)drag + thisOff, g_dragDbgStr1CF0, g_dragDbgStr1844, 4686);
    }
    u8* mgr2 = g_aptDragTarget;
    u8* nullTok = g_aptActionGlobal;
    *(u8**)((char*)mgr2 + 60) = nullTok;
}
