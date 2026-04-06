// BGCall_CASTargetInit
// Address: 0x80014EB4 | Size: 48 bytes
// FLAGS: -fno-elide-constructors -fno-schedule-insns

typedef unsigned char u8;

extern u8* g_bgMgr;      // r13-relative
extern int g_bgParam;    // r13-relative
extern int g_bgFlag;     // r13-relative
extern char g_casFuncPtr[16];  // r13-relative

void BGCall_CASTargetInit(int param) {
    // Match DOL load/store order
    u8* mgr = g_bgMgr;
    int zero = 0;
    g_bgParam = param;
    u8* vt = *(u8**)mgr;
    short adj = *(short*)(vt + 0x40);
    void (*func)(u8*, char*) = *(void (**)(u8*, char*))(vt + 0x44);
    g_bgFlag = zero;
    func(mgr + adj, g_casFuncPtr);
}
