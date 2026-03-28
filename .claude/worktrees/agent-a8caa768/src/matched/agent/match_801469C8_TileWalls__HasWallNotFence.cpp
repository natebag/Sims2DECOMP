// 0x801469C8 (108 bytes)
// TileWalls::HasWallNotFence(TileWallsSegment) const

class TileWalls { public: void HasWallNotFence(TileWallsSegment) const; };

__attribute__((naked))
void TileWalls::HasWallNotFence(TileWallsSegment) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030000\n.long 0x7C002038\n.long 0x7C002000\n.long 0x40820040\n.long 0x7C040378\n.long 0x48000399\n.long 0x2C030002\n.long 0x4182001C\n.long 0x2C03000C\n.long 0x41820014\n.long 0x2C03000D\n.long 0x4182000C\n.long 0x2C03000E\n.long 0x4082000C\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x68630001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
