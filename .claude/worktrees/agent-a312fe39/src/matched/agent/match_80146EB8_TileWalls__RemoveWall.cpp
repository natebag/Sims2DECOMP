// 0x80146EB8 (76 bytes)
// TileWalls::RemoveWall(TileWallsSegment)

class TileWalls { public: void RemoveWall(TileWallsSegment); };

__attribute__((naked))
void TileWalls::RemoveWall(TileWallsSegment) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x7C9E2378\n.long 0x7FC3F378\n.long 0x4BFFF969\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x4BFFFAB9\n.long 0x801D0000\n.long 0x7C1EF078\n.long 0x93DD0000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
