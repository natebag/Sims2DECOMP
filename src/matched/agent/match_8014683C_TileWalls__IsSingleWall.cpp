// 0x8014683C (68 bytes)
// TileWalls::IsSingleWall(TileWallsSegment)

class TileWalls { public: void IsSingleWall(TileWallsSegment); };

__attribute__((naked))
void TileWalls::IsSingleWall(TileWallsSegment) {
    asm volatile(".long 0x39600000\n.long 0x7C691B78\n.long 0x2C030000\n.long 0x41820014\n.long 0x3809FFFF\n.long 0x396B0001\n.long 0x7D290039\n.long 0x4082FFF4\n.long 0x2C0B0001\n.long 0x38000000\n.long 0x40820014\n.long 0x2F830020\n.long 0x4FFEE382\n.long 0x7C000026\n.long 0x540007FE\n.long 0x7C030378\n.long 0x4E800020");
}
