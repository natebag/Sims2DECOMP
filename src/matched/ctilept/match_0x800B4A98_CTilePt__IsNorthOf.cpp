// 0x800B4A98 CTilePt::IsNorthOf(CTilePt&) const (68B)
// Pattern: GetRow/GetColumn compare + CR7 bit extraction via mfcr + rlwinm
// LT uses plain '<' operator (SH=29 for CR7.LT extraction)
struct CTilePt {
    int GetRow() const;
    int GetColumn() const;
    int IsNorthOf(CTilePt& o) const;
};
int CTilePt::IsNorthOf(CTilePt& o) const { return GetRow() < o.GetRow(); }
