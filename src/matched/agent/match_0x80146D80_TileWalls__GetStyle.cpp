// 0x80146D80 TileWalls::GetStyle(TileWallsSegment) const (88B)

class TileWalls {
public:
    char _pad0[8];
    unsigned short m_styles[1];

    int HasWall(int seg) const;
    static int IsSingleWall(int seg);
    static int SegmentToIndex(int seg, int side);
    int GetStyle(int seg) const;
};

int TileWalls::GetStyle(int seg) const {
    IsSingleWall(seg);
    HasWall(seg);
    int idx = SegmentToIndex(seg, 0);
    return m_styles[idx];
}
