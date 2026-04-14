// 0x800B4B20 CTilePt::IsWestOf(CTilePt&) const (68B)
// Pattern: GetRow/GetColumn compare + CR7 bit extraction via mfcr + rlwinm
// LT uses plain '<' operator (SH=29 for CR7.LT extraction)
struct CTilePt {
    int GetRow() const;
    int GetColumn() const;
    int IsWestOf(CTilePt& o) const;
};
int CTilePt::IsWestOf(CTilePt& o) const { return GetColumn() < o.GetColumn(); }
