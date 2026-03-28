// 0x80146E4C (108 bytes)
// TileWalls::AddWall(TileWallsSegment)

class TileWalls { public: void AddWall(TileWallsSegment); };

__attribute__((naked))
void TileWalls::AddWall(TileWallsSegment) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C7E1B78\n.long 0x7FE3FB78\n.long 0x4BFFF9D5\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x4BFFF5C1\n.long 0x801E0000\n.long 0x2C1F0010\n.long 0x7C00FB78\n.long 0x901E0000\n.long 0x4182000C\n.long 0x2C1F0020\n.long 0x40820010\n.long 0x38000000\n.long 0xB01E0014\n.long 0xB01E0008\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
