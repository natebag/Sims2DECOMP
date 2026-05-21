// ASMPROC_replace_insn: match="mr 3,31" replacement="mr 3,4"
// 0x80146F78 (100B) TileWalls::Next(TileWallsSegment)

typedef int TileWallsSegment;

class TileWalls {
public:
    int m_flags;
    bool HasWall(TileWallsSegment seg) const;
    static int IsSingleWall(TileWallsSegment seg);
    int Next(TileWallsSegment seg) const;
};

int TileWalls::Next(TileWallsSegment seg) const {
    IsSingleWall(seg);
    do {
        seg <<= 1;
        if (HasWall(seg)) break;
    } while (seg <= 31);
    return (seg <= 31) ? seg : 0;
}
