// 0x80146134 (120 bytes)
// TileWalls::SetPlacement(TileWalls::SheerPlacement, TileWallsSegment)

class TileWalls { public: void SetPlacement(TileWalls::SheerPlacement, TileWallsSegment); };

__attribute__((naked))
void TileWalls::SetPlacement(TileWalls::SheerPlacement, TileWallsSegment) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7CBF2B78\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x7FE4FB78\n.long 0x48000845\n.long 0x7FE3FB78\n.long 0x480006E1\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x480005E5\n.long 0x2C030003\n.long 0x41810024\n.long 0x7C631A14\n.long 0x801E0004\n.long 0x39200003\n.long 0x7FAB1830\n.long 0x7D291830\n.long 0x7C094878\n.long 0x7D295B78\n.long 0x913E0004\n.long 0x7FE3FB78\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
