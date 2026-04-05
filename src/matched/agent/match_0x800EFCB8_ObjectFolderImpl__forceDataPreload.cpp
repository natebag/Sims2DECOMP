typedef unsigned char u8;

extern u8* g_sdaAC48;
void lookupPreload(u8*);

void ObjectFolderImpl_forceDataPreload(u8* self, u8* selector, int doForce) {
    if (*(int*)(selector + 0x9C) != 0) return;
    lookupPreload(g_sdaAC48);
    if (*(int*)selector != 0) return;
    u8* vt = *(u8**)self;
    short adj = *(short*)(vt + 0x148);
    void (*func)(u8*, u8*) = *(void (**)(u8*, u8*))(vt + 0x14C);
    func(self + adj, selector);
}
