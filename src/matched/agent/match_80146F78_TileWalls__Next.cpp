// 0x80146F78 (100 bytes)
// TileWalls::Next(TileWallsSegment) const

class TileWalls { public: void Next(TileWallsSegment) const; };

__attribute__((naked))
void TileWalls::Next(TileWallsSegment) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7C9F2378\n.long 0x7C832378\n.long 0x4BFFF8A9\n.long 0x57FF083C\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x4BFFF9F5\n.long 0x2C030000\n.long 0x4082000C\n.long 0x2C1F001F\n.long 0x4081FFE4\n.long 0x2C1F001F\n.long 0x38600000\n.long 0x41810008\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
