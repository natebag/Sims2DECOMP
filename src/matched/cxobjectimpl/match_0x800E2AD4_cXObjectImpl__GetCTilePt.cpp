// 0x800E2AD4 cXObjectImpl::GetCTilePt (68B)
// FLAGS: -felide-constructors

struct CTilePt {
    CTilePt(int, int, int);
};

struct cXObjectImpl {
    char pad[104];
    int m_field68;    // 0x68 = 104
    int m_field6C;    // 0x6C = 108
    char pad2[16];
    int m_field80;    // 0x80 = 128
    CTilePt GetCTilePt() const;
};

CTilePt cXObjectImpl::GetCTilePt() const {
    return CTilePt(m_field6C >> 4, m_field68 >> 4, m_field80);
}
