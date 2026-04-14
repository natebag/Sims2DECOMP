// 0x800B4ADC CTilePt::IsSouthOf(CTilePt&) const (68B)
// Pattern: GetRow/GetColumn compare + CR7 bit extraction via mfcr + rlwinm
// GT uses '? 1 : 0' ternary to force SH=30 for CR7.GT extraction
struct CTilePt {
    int GetRow() const;
    int GetColumn() const;
    int IsSouthOf(CTilePt& o) const;
};
int CTilePt::IsSouthOf(CTilePt& o) const { return (GetRow() > o.GetRow()) ? 1 : 0; }
