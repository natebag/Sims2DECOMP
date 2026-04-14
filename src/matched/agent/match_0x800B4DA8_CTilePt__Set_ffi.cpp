// 0x800B4DA8 CTilePt::Set(float, float, int) (52B)
struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_z;
};

void CTilePt__Set_ffi(CTilePt* self, float x, float y, int z) {
    self->m_z = (signed char)z;
    self->m_x = (int)x;
    self->m_y = (int)y;
}
