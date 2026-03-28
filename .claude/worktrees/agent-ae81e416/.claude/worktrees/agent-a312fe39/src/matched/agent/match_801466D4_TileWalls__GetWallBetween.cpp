// 0x801466D4 (120 bytes)
// TileWalls::GetWallBetween(TilePtDir)

class TileWalls { public: void GetWallBetween(TilePtDir); };

__attribute__((naked))
void TileWalls::GetWallBetween(TilePtDir) {
    asm volatile(".long 0x2C030003\n.long 0x41820054\n.long 0x4181001C\n.long 0x2C030001\n.long 0x41820038\n.long 0x4181003C\n.long 0x2C030000\n.long 0x41820024\n.long 0x48000050\n.long 0x2C030004\n.long 0x41820038\n.long 0x2C030007\n.long 0x41810040\n.long 0x2C030006\n.long 0x41800038\n.long 0x4800002C\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600008\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600004\n.long 0x4E800020\n.long 0x38600020\n.long 0x4E800020\n.long 0x38600010\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
