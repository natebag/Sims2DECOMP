// 0x800B4D78 CTilePt::Set(float, float) (48B)
struct CTilePt {
    signed char m_x;
    signed char m_y;
};

void CTilePt__Set_ff(CTilePt* self, float x, float y) {
    self->m_x = (int)x;
    self->m_y = (int)y;
}
