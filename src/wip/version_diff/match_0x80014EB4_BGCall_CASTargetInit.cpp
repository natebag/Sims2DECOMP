// FLAGS: -fno-schedule-insns
// BGCall_CASTargetInit
// Address: 0x80014EB4 | Size: 48 bytes
// FLAGS: -fno-elide-constructors -fno-schedule-insns

typedef unsigned char u8;

// SDA globals - using array syntax to force r13-relative addressing
extern u8* g_bgMgr[4];      // r13-relative: r13-0x58e4
extern int g_bgParam[4];    // r13-relative: r13-0x8050
extern int g_bgFlag[4];     // r13-relative: r13-0x8054
extern char g_casFuncPtr[16];  // r13-relative: r13-0x53e8

void BGCall_CASTargetInit(int param) {
    // Match DOL load/store order with explicit variable ordering
    u8* mgr = *g_bgMgr;  // First load - r3 available
    int zero = 0;        // Second - r0
    *g_bgParam = param;  // Third - store
    u8* vt = *(u8**)mgr; // Fourth - load vtable
    short adj = *(short*)(vt + 0x40);  // Fifth - load offset
    void (*func)(u8*, char*) = *(void (**)(u8*, char*))(vt + 0x44); // Sixth
    *g_bgFlag = zero;    // Store zero
    func(mgr + adj, g_casFuncPtr);
}
