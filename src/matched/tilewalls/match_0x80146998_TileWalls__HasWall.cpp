// 0x80146998 TileWalls::HasWall(TileWallsSegment) const (24B)

struct TileWalls {
    int m_flags;
    int HasWall(int seg) const;
};

int TileWalls::HasWall(int seg) const {
    int f = m_flags;
    f &= seg;
    f ^= seg;
    return f == 0;
}
