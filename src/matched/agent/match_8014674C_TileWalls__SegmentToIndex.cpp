// 0x8014674C (120 bytes)
// TileWalls::SegmentToIndex(TileWallsSegment, DiagonalSideSelector)

class TileWalls { public: void SegmentToIndex(TileWallsSegment, DiagonalSideSelector); };

__attribute__((naked))
void TileWalls::SegmentToIndex(TileWallsSegment, DiagonalSideSelector) {
    asm volatile(".long 0x68600001\n.long 0x39600000\n.long 0x392000FF\n.long 0x700A0001\n.long 0x41820024\n.long 0x7C630E70\n.long 0x396B0001\n.long 0x68600001\n.long 0x7D290E70\n.long 0x700A0001\n.long 0x4182000C\n.long 0x2C090000\n.long 0x4082FFE4\n.long 0x2C040002\n.long 0x41820038\n.long 0x41810018\n.long 0x2C040000\n.long 0x4182002C\n.long 0x2C040001\n.long 0x41820018\n.long 0x48000020\n.long 0x2C040003\n.long 0x41820014\n.long 0x2C040004\n.long 0x40820010\n.long 0x396B0001\n.long 0x48000008\n.long 0x396B0002\n.long 0x7D635B78\n.long 0x4E800020");
}
