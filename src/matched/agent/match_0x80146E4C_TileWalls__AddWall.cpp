// 0x80146E4C TileWalls::AddWall(TileWallsSegment) (108B)

class TileWalls {
public:
    unsigned int m_bits;
    char _pad4[4];
    unsigned short m_styles[10];

    static int IsSingleWall(int seg);
    int CanAdd(int seg) const;
    int AddWall(int seg);
};

int TileWalls::AddWall(int seg) {
    IsSingleWall(seg);
    CanAdd(seg);
    m_bits |= seg;
    if (seg == 16 || seg == 32) {
        ((volatile unsigned short*)m_styles)[6] = 0;
        ((volatile unsigned short*)m_styles)[0] = 0;
    }
    return seg;
}
