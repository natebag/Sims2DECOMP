// 0x801469B0 TileWalls::HasWall (24B)

struct TileWalls {
    int m_walls;
    int HasWall();
};

int TileWalls::HasWall() {
    int r = 1;
    if (m_walls == 0) r = 0;
    return r;
}
