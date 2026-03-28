// 0x80146614 (108 bytes)
// TileWalls::GetOppositeSegment(TileWallsSegment)

class TileWalls { public: void GetOppositeSegment(TileWallsSegment); };

__attribute__((naked))
void TileWalls::GetOppositeSegment(TileWallsSegment) {
    asm volatile(".long 0x2C030004\n.long 0x41820050\n.long 0x41810018\n.long 0x2C030001\n.long 0x41820034\n.long 0x2C030002\n.long 0x41820034\n.long 0x48000048\n.long 0x2C030010\n.long 0x4D820020\n.long 0x41810010\n.long 0x2C030008\n.long 0x4182002C\n.long 0x48000030\n.long 0x2C030020\n.long 0x4D820020\n.long 0x48000024\n.long 0x38600004\n.long 0x4E800020\n.long 0x38600008\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
