// 0x801460C4 TileWalls::GetPlacement(TileWallsSegment) const (112B)

class TileWalls {
public:
    char _pad0[4];
    unsigned int m_placement;

    int HasWall(int seg) const;
    static int IsSingleWall(int seg);
    static int SegmentToIndex(int seg, int side);
    int GetPlacement(int seg) const;
};

int TileWalls::GetPlacement(int seg) const {
    HasWall(seg);
    IsSingleWall(seg);
    int idx = SegmentToIndex(seg, 0);
    if (idx > 3) return 3;
    idx += idx;
    return (int)(m_placement & (3u << idx)) >> idx;
}
