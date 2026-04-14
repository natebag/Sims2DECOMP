// 0x800B4838 CTilePt::operator-=(CTilePt&) (40B)
// FLAGS: -fno-elide-constructors

struct CTilePt {
    char x;
    char y;
    CTilePt& operator-=(CTilePt& other);
};

CTilePt& CTilePt::operator-=(CTilePt& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
