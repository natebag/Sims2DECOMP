// 0x8003063C EIWallPart::isDiagonal(TileWallsSegment) (24 B)
// FLAGS: -fno-schedule-insns
typedef int TileWallsSegment;
static int isDiagonal(TileWallsSegment seg) { return (seg & 0x30) != 0; }
