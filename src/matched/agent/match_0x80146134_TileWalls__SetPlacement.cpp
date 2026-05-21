// 0x80146134 TileWalls::SetPlacement(TileWalls::SheerPlacement, TileWallsSegment) (120B)

class TileWalls {
public:
    char _pad0[4];
    unsigned int m_placement;

    int HasWall(int seg) const;
    static int IsSingleWall(int seg);
    static int SegmentToIndex(int seg, int side);
    int SetPlacement(int placement, int seg);
};

int TileWalls::SetPlacement(int placement, int seg) {
    HasWall(seg);
    IsSingleWall(seg);
    int idx = SegmentToIndex(seg, 0);
    if (idx <= 3) {
        idx += idx;
        m_placement = (m_placement & ~(3u << idx)) | ((unsigned int)placement << idx);
    }
    return seg;
}
