// 0x80147020 TileWalls::ConvertToWorldCoords (48B)
// If m_field36 != 0, call helper with (4 - m_field36)

struct TileWalls {
    char pad[36];
    int m_rot;
    void ConvertToWorldCoords();
    void Apply(int r);
};

void TileWalls::ConvertToWorldCoords() {
    int v = m_rot;
    if (v == 0) return;
    Apply(4 - v);
}
