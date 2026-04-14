// 0x800B4560 CTilePt::GetXf(void) const (56B)
struct CTilePt {
    signed char m_x;
    signed char m_y;
};

float CTilePt__GetXf(CTilePt* self) {
    return (float)self->m_x;
}
