// 0x801469b0 TileWalls::HasWall (24b)

struct TileWalls {
    int m_count;
    int HasWall() const;
};

int TileWalls::HasWall() const {
    int r = 1;
    if (!m_count) r = 0;
    return r;
}
