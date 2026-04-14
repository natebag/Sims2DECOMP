// 0x80151A90 cFixedWorldImpl::OutOfBuildingBounds(CTilePt&, bool) const (128B)

struct CTilePt {
    signed char x;
    signed char y;
};

struct cFixedWorldImpl {
    char pad[0x14];
    int m_gridWidth;
    int m_gridHeight;

    int OutOfBuildingBounds(const CTilePt& pt, bool strict) const;
};

int cFixedWorldImpl::OutOfBuildingBounds(const CTilePt& pt, bool strict) const {
    int xmin, ymin, xlim, ylim;
    if (strict) {
        xmin = 2;
        ymin = 2;
        xlim = m_gridWidth - 2;
        ylim = m_gridHeight - 2;
    } else {
        xmin = 1;
        ymin = 1;
        xlim = m_gridWidth - 1;
        ylim = m_gridHeight - 1;
    }
    if (pt.x < xmin || pt.x >= xlim || pt.y < ymin || pt.y >= ylim) return 1;
    return 0;
}
