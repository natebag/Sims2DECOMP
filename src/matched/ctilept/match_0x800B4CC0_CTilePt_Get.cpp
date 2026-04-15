// 0x800B4CC0 CTilePt::Get(int*, int*) const (28B)

struct CTilePt {
    signed char m_x;
    signed char m_y;
    void Get(int* x, int* y) const;
};

void CTilePt::Get(int* x, int* y) const {
    *x = m_x;
    *y = m_y;
}
