// FLAGS: -fno-rtti
// 0x80146AB4 (200B) TileWalls::HasDiagonalNotFence(void) const

struct TileWalls {
    int m_walls;
    int GetStyle(int segment) const;
    bool HasDiagonalNotFence() const;
};

int TileWalls::GetStyle(int segment) const {
    return 0;
}

bool TileWalls::HasDiagonalNotFence() const {
    if (m_walls & 0x10) {
        int style = GetStyle(16);
        int isFence = 0;
        if (style == 2) isFence = 1;
        else if (style == 12) isFence = 1;
        else if (style == 13) isFence = 1;
        else if (style == 14) isFence = 1;
        if (isFence == 0) return true;
    }
    if (m_walls & 0x20) {
        int style = GetStyle(32);
        int isFence = 0;
        if (style == 2) isFence = 1;
        else if (style == 12) isFence = 1;
        else if (style == 13) isFence = 1;
        else if (style == 14) isFence = 1;
        if (isFence == 0) return true;
    }
    return false;
}
