// 0x800B46D8 (76B) CTilePt::CTilePt(TilePtDir, int)

extern char CTilePt_dirTable[];  // 0x80485E20

class CTilePt {
public:
    signed char m_0;
    signed char m_1;
    signed char m_2;
    CTilePt& operator=(CTilePt& other);
    CTilePt(int dir, int z);
};

CTilePt::CTilePt(int dir, int z) {
    *this = *(CTilePt*)(CTilePt_dirTable + dir * 3);
    m_2 = (signed char)z;
}
