// 0x80146a9c TileWalls::HasDiagonal(void) const (24B)

struct TileWalls {
    int m_data;
    int HasDiagonal(void) const;
};

int TileWalls::HasDiagonal(void) const {
    return (m_data & 0x30) != 0;
}
