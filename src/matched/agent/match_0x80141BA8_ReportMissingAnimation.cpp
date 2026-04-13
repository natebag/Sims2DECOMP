// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

void ReportMissingAnimation(u8* person, char* name, int param) {
    u8* obj = *(u8**)person;
    u8* vt1 = *(u8**)obj;
    u8* inner = *(u8**)(vt1 + 0x18);
    short adj1 = *(short*)(inner + 0x28);
    void* (*func1)(u8*, int) = *(void* (**)(u8*, int))(inner + 0x2C);
    param = 0x43;
    func1((u8*)vt1 + adj1, param);
    u8* obj2 = *(u8**)person;
    u8* vt2 = *(u8**)(obj2 + 4);
    short adj2 = *(short*)(vt2 + 0x110);
    void (*func2)(u8*, int) = *(void (**)(u8*, int))(vt2 + 0x114);
    func2(obj2 + adj2, 0x43);
}
