// 0x80146A34 (104 bytes)
// TileWalls::HasFenceNotWall(TileWallsSegment) const

class TileWalls { public: void HasFenceNotWall(TileWallsSegment) const; };

__attribute__((naked))
void TileWalls::HasFenceNotWall(TileWallsSegment) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030000\n.long 0x7C002038\n.long 0x7C002000\n.long 0x4082003C\n.long 0x7C040378\n.long 0x4800032D\n.long 0x2C030002\n.long 0x4182001C\n.long 0x2C03000C\n.long 0x41820014\n.long 0x2C03000D\n.long 0x4182000C\n.long 0x2C03000E\n.long 0x4082000C\n.long 0x38600001\n.long 0x48000010\n.long 0x38600000\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
