typedef unsigned char u8;

extern char g_tutString[16];

void ObjectModuleImpl_ShowTutorialInfo(u8* self) {
    u8* obj = *(u8**)(self + 0x2088);
    if (obj == 0) return;
    u8* inner = *(u8**)(obj + 4);
    u8* vt = *(u8**)(inner + 4);
    short adj = *(short*)(vt + 0xF8);
    void (*func)(u8*, char*) = *(void (**)(u8*, char*))(vt + 0xFC);
    func(inner + adj, g_tutString);
}
