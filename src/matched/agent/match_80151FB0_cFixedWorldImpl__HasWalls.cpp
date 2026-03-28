// 0x80151FB0 (104 bytes)
// cFixedWorldImpl::HasWalls(CTilePt &, TileWallsSegment)

class cFixedWorldImpl { public: void HasWalls(CTilePt &, TileWallsSegment); };

__attribute__((naked))
void cFixedWorldImpl::HasWalls(CTilePt &, TileWallsSegment) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C9D2378\n.long 0x83830038\n.long 0x7CBB2B78\n.long 0x7FA3EB78\n.long 0x4BF62CD9\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62CD9\n.long 0x817C000C\n.long 0x57DE103A\n.long 0x54631838\n.long 0x7D3E582E\n.long 0x7C6918AE\n.long 0x7C63D838\n.long 0x7C63DA78\n.long 0x20030000\n.long 0x7C601914\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
