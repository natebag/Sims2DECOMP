/* TileWalls::SetFloorValue(FloorPattern, DiagonalSideSelector) at 0x80146FF8 (40B) */

struct TileWalls_SFV {
    int _pad0[2];
    unsigned short m_floorA;
    char _gap[10];
    unsigned short m_floorB;
    unsigned short SetFloorValue(unsigned short newPat, int sel);
};

unsigned short TileWalls_SFV::SetFloorValue(unsigned short newPat, int sel) {
    unsigned short old;
    if ((unsigned)(sel - 1) <= 1u) {
        old = m_floorA;
        m_floorA = newPat;
    } else {
        old = m_floorB;
        m_floorB = newPat;
    }
    return old;
}
