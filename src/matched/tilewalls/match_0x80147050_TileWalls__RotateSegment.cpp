// 0x80147050 TileWalls::RotateSegment(TileWallsSegment, int) (28B)

extern int g_RotateSegmentLookup[4][64];

struct TileWalls {
    static int RotateSegment(int segment, int rotation);
};

int TileWalls::RotateSegment(int segment, int rotation) {
    return g_RotateSegmentLookup[rotation][segment];
}
