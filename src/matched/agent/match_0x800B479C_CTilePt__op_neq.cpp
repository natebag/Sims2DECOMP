// 0x800B479C CTilePt::operator!=(CTilePt&) const (48B)
struct CTilePt {
    unsigned char m_x;
    unsigned char m_y;
};

int CTilePt__op_neq(CTilePt* self, CTilePt& o) {
    int r = 0;
    if (o.m_x != self->m_x || o.m_y != self->m_y) r = 1;
    return r;
}
