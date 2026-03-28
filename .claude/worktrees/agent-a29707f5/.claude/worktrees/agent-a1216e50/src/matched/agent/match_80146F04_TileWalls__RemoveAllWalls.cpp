/* TileWalls::RemoveAllWalls - 0x80146F04 (12 bytes) */

class TileWalls {
public:
    int m_flags;
    void RemoveAllWalls();
};

void TileWalls::RemoveAllWalls() {
    m_flags = 0;
}
