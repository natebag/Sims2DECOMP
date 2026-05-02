// 0x800B4620 CTilePt::CTilePt(TilePt&, int) (28B)

struct TilePt {
    char _pad[3];
    char x;
    char _pad2[3];
    char y;
};

struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt(TilePt& tp, int z_);
};

CTilePt::CTilePt(TilePt& tp, int z_) {
    x = tp.x;
    y = tp.y;
    z = (char)z_;
}
