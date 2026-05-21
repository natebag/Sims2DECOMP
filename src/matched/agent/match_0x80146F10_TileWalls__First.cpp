// 0x80146F10 (104B) TileWalls::First()

typedef int TileWallsSegment;

class TileWalls {
public:
    int m_flags;
    bool HasWall(TileWallsSegment seg) const;
    static int IsSingleWall(TileWallsSegment seg);
    int First() const;
};

int TileWalls::First() const {
    if (m_flags != 0) {
        TileWallsSegment seg = 1;
        while (!HasWall(seg)) seg <<= 1;
        IsSingleWall(seg);
        return seg;
    }
    return 0;
}
