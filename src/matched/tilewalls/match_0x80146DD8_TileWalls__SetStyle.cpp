// 0x80146DD8 TileWalls::SetStyle(WallStyle, TileWallsSegment) (116B)

class TileWalls {
public:
    char _pad0[8];
    unsigned short m_styles[6];

    int HasWall(int seg) const;
    static int IndexToSegment(int idx, int* outSide);
    int SetStyle(int style, int seg);
};

int TileWalls::SetStyle(int style, int seg) {
    if (seg != 0xFF) HasWall(seg);
    for (unsigned int i = 0; i <= 5; i++) {
        if (IndexToSegment(i, 0) & seg) {
            m_styles[i] = (unsigned short)style;
        }
    }
    return seg;
}
