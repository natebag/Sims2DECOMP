/* EIWallPart::isDiagonal(TileWallsSegment) - 0x8003063C (24 bytes) */

typedef int TileWallsSegment;

struct EIWallPart {
    static int isDiagonal(TileWallsSegment seg);
};

int EIWallPart::isDiagonal(TileWallsSegment seg) {
    if (seg & 0x30) {
        return 1;
    }
    return 0;
}
