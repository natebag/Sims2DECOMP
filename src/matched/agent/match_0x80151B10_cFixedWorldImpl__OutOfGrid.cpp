// 0x80151B10 cFixedWorldImpl::OutOfGrid(CTilePt&) const (72B)

struct CTilePt {
    signed char x;
    signed char y;
};

struct cFixedWorldImpl {
    char pad[0x14];
    int m_gridWidth;
    int m_gridHeight;

    int OutOfGrid(const CTilePt& pt) const;
};

int cFixedWorldImpl::OutOfGrid(const CTilePt& pt) const {
    if (pt.x < 0 || pt.x >= m_gridWidth || pt.y < 0 || pt.y >= m_gridHeight) return 1;
    return 0;
}
