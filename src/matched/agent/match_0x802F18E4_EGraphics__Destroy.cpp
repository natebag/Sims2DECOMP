// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

void EGraphics_Destroy(u8* self, u8* surface) {
    if (surface == 0) return;
    u8* vt1 = *(u8**)self;
    short adj1 = *(short*)(vt1 + 0x40);
    void (*func1)(u8*) = *(void (**)(u8*))(vt1 + 0x44);
    func1(self + adj1);
    *(int*)(self + 0x30) = *(int*)(self + 0x30) - 1;
    u8* vt2 = *(u8**)self;
    short adj2 = *(short*)(vt2 + 0x210);
    void (*func2)(u8*, u8*) = *(void (**)(u8*, u8*))(vt2 + 0x214);
    func2(self + adj2, surface);
}
