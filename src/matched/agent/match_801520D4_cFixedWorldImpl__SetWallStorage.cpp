// 0x801520D4 (104 bytes)
// cFixedWorldImpl::SetWallStorage(CTilePt &, TileWallStorage &)

class cFixedWorldImpl { public: void SetWallStorage(CTilePt &, TileWallStorage &); };

__attribute__((naked))
void cFixedWorldImpl::SetWallStorage(CTilePt &, TileWallStorage &) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7C9D2378\n.long 0x83830038\n.long 0x7CBB2B78\n.long 0x7FA3EB78\n.long 0x4BF62BB5\n.long 0x7C7E1B78\n.long 0x7FA3EB78\n.long 0x4BF62BB5\n.long 0x815C000C\n.long 0x57DE103A\n.long 0x54631838\n.long 0x817B0000\n.long 0x819B0004\n.long 0x7D3E502E\n.long 0x7D291A14\n.long 0x91690000\n.long 0x91890004\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
