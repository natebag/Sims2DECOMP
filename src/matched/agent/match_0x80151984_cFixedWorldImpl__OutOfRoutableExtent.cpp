// 0x80151984 cFixedWorldImpl::OutOfRoutableExtent(CTilePt&) const (80B)

struct CTilePt {
    signed char x;
    signed char y;
};

struct cFixedWorldImpl {
    char pad[0x1C];
    int m_routableMinX;
    int m_routableMaxX;
    int m_routableMinY;
    int m_routableMaxY;

    int OutOfRoutableExtent(const CTilePt& pt) const;
};

int cFixedWorldImpl::OutOfRoutableExtent(const CTilePt& pt) const {
    int out = 0;
    if (pt.x < m_routableMinX || pt.x > m_routableMaxX || pt.y < m_routableMinY || pt.y > m_routableMaxY)
        out = 1;
    return out;
}
