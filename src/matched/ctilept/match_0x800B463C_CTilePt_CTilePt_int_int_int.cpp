// 0x800B463C CTilePt::CTilePt(int, int, int) (60B)

struct CTilePt {
    char x;
    char y;
    char z;
    CTilePt(int x_, int y_, int z_);
};

CTilePt::CTilePt(int x_, int y_, int z_) {
    x = (char)x_;
    y = (char)y_;
    if ((int)x != x_) x = 0;
    if ((int)y != y_) y = 0;
    z = (char)z_;
}
