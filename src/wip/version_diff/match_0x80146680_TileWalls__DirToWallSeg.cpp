// 0x80146680 TileWalls::DirToWallSeg (84B)

enum TilePtDir {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3,
    NORTHEAST = 4,
    NORTHWEST = 5,
    SOUTHEAST = 6,
    SOUTHWEST = 7,
};

struct TileWalls {
    static int DirToWallSeg(TilePtDir dir);
};

enum TileWallsSegment {
    SEG_NONE = 0x0,
    SEG_N = 0x1,
    SEG_NE = 0x2,
    SEG_E = 0x4,
    SEG_SE = 0x8,
    SEG_S = 0x10,
    SEG_SW = 0x20,
    SEG_W = 0x40,
    SEG_NW = 0x80,
};

int TileWalls::DirToWallSeg(TilePtDir dir) {
    switch (dir) {
        case NORTH:
        case SOUTH:
        case EAST:
            return SEG_NE;
        case WEST:
            return SEG_N;
        case NORTHEAST:
        case NORTHWEST:
            return SEG_SW;
        case SOUTHEAST:
            return SEG_S;
        case SOUTHWEST:
            return SEG_N;
        default:
            return SEG_S;
    }
}
