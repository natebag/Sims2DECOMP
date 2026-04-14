// 0x800B4BA8 CTilePt::SameRowParity(CTilePt&) const (76B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    int GetRow() const;
    int SameRowParity(CTilePt& other) const;
};

int CTilePt::SameRowParity(CTilePt& other) const {
    return ((GetRow() & 1) ^ (other.GetRow() & 1)) == 0;
}
