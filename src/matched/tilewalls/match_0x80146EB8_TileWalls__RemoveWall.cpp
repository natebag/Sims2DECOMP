// 0x80146EB8 TileWalls::RemoveWall(TileWallsSegment) (76B)

class TileWalls {
public:
    unsigned int m_bits;

    int HasWall(int seg) const;
    static int IsSingleWall(int seg);
    void RemoveWall(int seg);
};

void TileWalls::RemoveWall(int seg) {
    IsSingleWall(seg);
    HasWall(seg);
    m_bits &= ~seg;
}
