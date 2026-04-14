// FLAGS: -fno-elide-constructors
// 0x801D9398 PRGTarget::GetUnlockedFashions(void) (112B)
// Triple-vtable dispatch template — varies only in final immediate (1 for Fashions)

typedef unsigned char u8;

extern u8* g_familyMgr2;

int PRGTarget_GetUnlockedFashions(u8* self) {
    u8* mgr = g_familyMgr2;
    u8* vt1 = *(u8**)mgr;
    short adj1 = *(short*)(vt1 + 0x120);
    void* (*func1)(u8*, int) = *(void* (**)(u8*, int))(vt1 + 0x124);
    u8* r1 = (u8*)func1(mgr + adj1, 1);

    u8* vt2 = *(u8**)r1;
    short adj2 = *(short*)(vt2 + 0x148);
    void* (*func2)(u8*) = *(void* (**)(u8*))(vt2 + 0x14C);
    u8* r2 = (u8*)func2(r1 + adj2);

    u8* vt3 = *(u8**)r2;
    short adj3 = *(short*)(vt3 + 0x20);
    int (*func3)(u8*, int) = *(int (**)(u8*, int))(vt3 + 0x24);
    return func3(r2 + adj3, 1);
}
