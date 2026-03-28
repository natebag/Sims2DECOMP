// 0x80146D80 (88 bytes)
// TileWalls::GetStyle(TileWallsSegment) const

class TileWalls { public: void GetStyle(TileWallsSegment) const; };

__attribute__((naked))
void TileWalls::GetStyle(TileWallsSegment) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9E2378\n.long 0x7C7D1B78\n.long 0x7FC3F378\n.long 0x4BFFFAA1\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x4BFFFBF1\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x4BFFF999\n.long 0x5463083C\n.long 0x3BBD0008\n.long 0x7C7D1A2E\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
