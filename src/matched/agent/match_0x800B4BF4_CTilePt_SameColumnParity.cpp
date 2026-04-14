// 0x800B4BF4 CTilePt::SameColumnParity(CTilePt&) const (76B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    int GetColumn() const;
    int SameColumnParity(CTilePt& other) const;
};

int CTilePt::SameColumnParity(CTilePt& other) const {
    return ((GetColumn() & 1) ^ (other.GetColumn() & 1)) == 0;
}
