// 0x800B4598 CTilePt::GetYf(void) const (56B)
struct CTilePt {
    signed char m_x;
    signed char m_y;
};

float CTilePt__GetYf(CTilePt* self) {
    return (float)self->m_y;
}
