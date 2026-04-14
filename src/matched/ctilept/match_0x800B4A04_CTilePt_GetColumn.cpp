// 0x800B4A04 CTilePt::GetColumn(void) const (24B)

struct CTilePt {
    char x;
    char y;
    int GetColumn() const;
};

int CTilePt::GetColumn() const {
    return (int)x - (int)y;
}
