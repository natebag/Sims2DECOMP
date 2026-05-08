// 0x800B45FC CTilePt::CTilePt(FTilePt &, int) (36B)

struct FTilePt {
    int x;
    int y;
};

struct CTilePt {
    signed char m_x;
    signed char m_y;
    signed char m_z;
    CTilePt(FTilePt& f, int z);
};

CTilePt::CTilePt(FTilePt& f, int z) {
    m_x = (signed char)(f.y >> 4);
    m_y = (signed char)(f.x >> 4);
    m_z = (signed char)z;
}
