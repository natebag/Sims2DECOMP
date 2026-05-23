typedef unsigned char u8;

void ERoomWall_SafeDelete(u8* obj) {
    if (obj == 0) return;
    u8* vt = *(u8**)(obj + 0x3C);
    short adj = *(short*)(vt + 0x08);
    void (*func)(u8*, int) = *(void (**)(u8*, int))(vt + 0x0C);
    func(obj + adj, 3);
}
