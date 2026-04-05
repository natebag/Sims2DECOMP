typedef unsigned char u8;

extern u8* g_simMgr;

int HouseImpl_PrepareForBudgetWindow(u8* self) {
    u8* mgr = g_simMgr;
    u8* vt1 = *(u8**)mgr;
    short adj1 = *(short*)(vt1 + 0x80);
    int (*func1)(u8*) = *(int (**)(u8*))(vt1 + 0x84);
    int result = func1(mgr + adj1);
    if (result != 1) {
        u8* vt2 = *(u8**)self;
        short adj2 = *(short*)(vt2 + 0x88);
        void (*func2)(u8*) = *(void (**)(u8*))(vt2 + 0x8C);
        func2(self + adj2);
    }
}
