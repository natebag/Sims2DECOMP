// 0x800B49EC CTilePt::GetRow(void) const (24B)

struct CTilePt {
    char x;
    char y;
    int GetRow() const;
};

int CTilePt::GetRow() const {
    return (int)x + (int)y;
}
