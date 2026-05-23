// 0x801468B8 TileWalls::TileWalls(TileWalls const&) (92B)

struct TileWalls {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    TileWalls(const TileWalls& other);
};

TileWalls::TileWalls(const TileWalls& other) {
    __builtin_memcpy(this, &other, sizeof(TileWalls));
}
