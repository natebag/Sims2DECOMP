// 0x800B4678 (96B) CTilePt::CTilePt(float, float, int)

class CTilePt {
public:
    signed char m_0;
    signed char m_1;
    signed char m_2;
    CTilePt(float fx, float fy, int z);
};

CTilePt::CTilePt(float fx, float fy, int z) {
    int ix = (int)fx;
    int iy = (int)fy;
    m_0 = (signed char)ix;
    m_1 = (signed char)iy;
    if ((int)(signed char)ix != ix) m_0 = 0;
    if ((int)(signed char)m_1 != iy) m_1 = 0;
    m_2 = (signed char)z;
}
