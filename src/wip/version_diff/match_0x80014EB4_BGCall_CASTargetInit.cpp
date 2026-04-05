// VERSION_DIFF: SDA load/store scheduling order
typedef unsigned char u8;

extern u8* g_bgMgr;
extern int g_bgParam;
extern int g_bgFlag;
extern char g_casFuncPtr[16];

void BGCall_CASTargetInit(int param) {
    u8* mgr = g_bgMgr;
    g_bgParam = param;
    g_bgFlag = 0;
    u8* vt = *(u8**)mgr;
    short adj = *(short*)(vt + 0x40);
    void (*func)(u8*, char*) = *(void (**)(u8*, char*))(vt + 0x44);
    func(mgr + adj, g_casFuncPtr);
}
