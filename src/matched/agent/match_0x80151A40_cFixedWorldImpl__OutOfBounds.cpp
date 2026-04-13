// 0x80151A40 cFixedWorldImpl::OutOfBounds(CTilePt&) const (80B)

struct CTilePt {
    signed char x;
    signed char y;
};

struct cFixedWorldImpl {
    char pad[0x14];
    int m_gridWidth;
    int m_gridHeight;

    int OutOfBounds(const CTilePt& pt) const;
};

int cFixedWorldImpl::OutOfBounds(const CTilePt& pt) const {
    if (pt.x <= 0 || pt.x >= m_gridWidth - 1 || pt.y <= 0 || pt.y >= m_gridHeight - 1) return 1;
    return 0;
}
