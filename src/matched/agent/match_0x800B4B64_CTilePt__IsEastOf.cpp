// 0x800B4B64 CTilePt::IsEastOf(CTilePt&) const (68B)
// Pattern: GetRow/GetColumn compare + CR7 bit extraction via mfcr + rlwinm
// GT uses '? 1 : 0' ternary to force SH=30 for CR7.GT extraction
struct CTilePt {
    int GetRow() const;
    int GetColumn() const;
    int IsEastOf(CTilePt& o) const;
};
int CTilePt::IsEastOf(CTilePt& o) const { return (GetColumn() > o.GetColumn()) ? 1 : 0; }
