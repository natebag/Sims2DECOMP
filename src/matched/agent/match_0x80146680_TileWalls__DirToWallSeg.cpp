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

int TileWalls::DirToWallSeg(TilePtDir dir) {
    switch (dir) {
        case NORTH:
        case SOUTH:
            return 1;
        case EAST:
        case WEST:
            return 2;
        case NORTHEAST:
        case NORTHWEST:
            return 32;
        case SOUTHEAST:
        case SOUTHWEST:
            return 16;
        default:
            return 1;
    }
}
