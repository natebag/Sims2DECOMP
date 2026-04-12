// 0x8003063C EIWallPart::isDiagonal (24b)

typedef int TileWallsSegment;

struct EIWallPart {
    static int isDiagonal(TileWallsSegment seg);
};

int EIWallPart::isDiagonal(TileWallsSegment seg) {
    int r = 1;
    if (!(seg & 0x30)) {
        r = 0;
    }
    return r;
}
