// 0x800B4CDC CTilePt::Get(int*, int*, int*) const (36B)
struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_z;
};

void CTilePt__Get(CTilePt* self, int* x, int* y, int* z) {
    *x = self->m_x;
    *y = self->m_y;
    *z = self->m_z;
}
