// 0x800B45DC CTilePt::CTilePt(CTilePt&) (32B)
// FLAGS: -fno-elide-constructors
struct CTilePt {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    CTilePt(CTilePt& other);
};
CTilePt::CTilePt(CTilePt& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}
