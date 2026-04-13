// 0x80146a9c TileWalls::HasDiagonal (24b)

struct TileWalls {
    int m_flags;
    int HasDiagonal() const;
};

int TileWalls::HasDiagonal() const {
    int r = 1;
    if (!(m_flags & 0x30)) r = 0;
    return r;
}
