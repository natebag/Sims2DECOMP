// 0x800B4A1C CTilePt::IsoCompare(CTilePt&) const (124B)
// FLAGS: -O2 -msdata=eabi -G 8

struct CTilePt {
    int GetRow() const;
    int GetColumn() const;
    int IsoCompare(CTilePt& other) const;
};

int CTilePt::IsoCompare(CTilePt& other) const {
    if (GetRow() == other.GetRow())
        return GetColumn() < other.GetColumn();
    return GetRow() < other.GetRow();
}
