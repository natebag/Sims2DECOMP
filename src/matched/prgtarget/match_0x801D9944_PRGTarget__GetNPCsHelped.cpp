// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

extern u8* g_familyMgr2;
extern int g_npcHelpConst[4];

int PRGTarget_GetNPCsHelped(u8* self) {
    u8* mgr = g_familyMgr2;
    int param = g_npcHelpConst[0];
    u8* vt1 = *(u8**)mgr;
    short adj1 = *(short*)(vt1 + 0x120);
    void* (*func1)(u8*, int) = *(void* (**)(u8*, int))(vt1 + 0x124);
    u8* result = (u8*)func1(mgr + adj1, param);
    u8* vt2 = *(u8**)result;
    short adj2 = *(short*)(vt2 + 0x150);
    int (*func2)(u8*, int) = *(int (**)(u8*, int))(vt2 + 0x154);
    return func2(result + adj2, 10);
}
