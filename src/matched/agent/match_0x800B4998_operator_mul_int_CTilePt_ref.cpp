// 0x800B4998 operator*(int, CTilePt&) (84B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt(int x_, int y_, int z_);
};

CTilePt operator*(int scale, CTilePt& pt) {
    return CTilePt(scale * (int)pt.x, scale * (int)pt.y, (int)pt.z);
}
