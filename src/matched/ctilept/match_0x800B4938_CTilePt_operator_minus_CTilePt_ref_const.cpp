// 0x800B4938 CTilePt::operator-(CTilePt&) const (96B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt(int x_, int y_, int z_);
    CTilePt operator-(CTilePt& other) const;
};

CTilePt CTilePt::operator-(CTilePt& other) const {
    return CTilePt((int)x - (int)other.x, (int)y - (int)other.y, (int)z);
}
