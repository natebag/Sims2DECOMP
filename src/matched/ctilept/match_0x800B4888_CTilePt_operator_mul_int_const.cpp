// 0x800B4888 CTilePt::operator*(int) const (80B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt(int x_, int y_, int z_);
    CTilePt operator*(int scale) const;
};

CTilePt CTilePt::operator*(int scale) const {
    return CTilePt(scale * (int)x, scale * (int)y, (int)z);
}
