// 0x80146A9C TileWalls::HasDiagonal (24B)

struct TileWalls_HD {
    int m_walls;
    int HasDiagonal();
};

int TileWalls_HD::HasDiagonal() {
    int r = 1;
    if ((m_walls & 0x30) == 0) r = 0;
    return r;
}
