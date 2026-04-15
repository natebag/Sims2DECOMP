/* TileWalls::GetFloorValue(DiagonalSideSelector) const - 0x80146FDC (28 bytes) */

class TileWalls {
public:
    char pad0[8];
    short m_short_8;
    char pad1[10];
    short m_short_20;

    unsigned short GetFloorValue(int sel) const;
};

unsigned short TileWalls::GetFloorValue(int sel) const {
    sel -= 1;
    if ((unsigned)sel <= 1) return m_short_8;
    return m_short_20;
}
