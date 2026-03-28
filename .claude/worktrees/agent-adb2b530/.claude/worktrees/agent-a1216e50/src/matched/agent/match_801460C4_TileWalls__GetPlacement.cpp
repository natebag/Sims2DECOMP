// 0x801460C4 (112 bytes)
// TileWalls::GetPlacement(TileWallsSegment) const

class TileWalls { public: void GetPlacement(TileWallsSegment) const; };

__attribute__((naked))
void TileWalls::GetPlacement(TileWallsSegment) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x7C7F1B78\n.long 0x480008BD\n.long 0x7FC3F378\n.long 0x48000759\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x4800065D\n.long 0x7C691B78\n.long 0x2C090003\n.long 0x41810020\n.long 0x7D294A14\n.long 0x807F0004\n.long 0x38000003\n.long 0x7C004830\n.long 0x7C630038\n.long 0x7C634E30\n.long 0x48000008\n.long 0x38600003\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
