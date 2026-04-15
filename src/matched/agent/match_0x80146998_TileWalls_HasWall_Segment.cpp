// 0x80146998 (24B) TileWalls::HasWall(TileWallsSegment) const

struct TileWalls {
    unsigned int m_bits;
    bool HasWall(int seg) const;
};

bool TileWalls::HasWall(int seg) const {
    return (m_bits & seg) == seg;
}
