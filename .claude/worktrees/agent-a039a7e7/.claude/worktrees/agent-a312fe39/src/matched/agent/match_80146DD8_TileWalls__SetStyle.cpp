// 0x80146DD8 (116 bytes)
// TileWalls::SetStyle(WallStyle, TileWallsSegment)

class TileWalls { public: void SetStyle(WallStyle, TileWallsSegment); };

__attribute__((naked))
void TileWalls::SetStyle(WallStyle, TileWallsSegment) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x7CBD2B78\n.long 0x7C7F1B78\n.long 0x7C9C2378\n.long 0x2C1D00FF\n.long 0x4182000C\n.long 0x7FA4EB78\n.long 0x4BFFFB99\n.long 0x3BDF0008\n.long 0x3BE00000\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x4BFFF9B1\n.long 0x7C60E839\n.long 0x41820008\n.long 0xB39E0000\n.long 0x3BFF0001\n.long 0x3BDE0002\n.long 0x281F0005\n.long 0x4081FFDC\n.long 0x7FA3EB78\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
