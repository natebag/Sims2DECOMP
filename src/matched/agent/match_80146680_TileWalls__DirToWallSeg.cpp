// 0x80146680 (84 bytes)
// TileWalls::DirToWallSeg(TilePtDir)

class TileWalls { public: void DirToWallSeg(TilePtDir); };

__attribute__((naked))
void TileWalls::DirToWallSeg(TilePtDir) {
    asm volatile(".long 0x2C030003\n.long 0x40810018\n.long 0x2C030005\n.long 0x40810030\n.long 0x2C030007\n.long 0x41810038\n.long 0x4800002C\n.long 0x2C030002\n.long 0x40800014\n.long 0x2C030000\n.long 0x41800024\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600002\n.long 0x4E800020\n.long 0x38600020\n.long 0x4E800020\n.long 0x38600010\n.long 0x4E800020\n.long 0x38600001\n.long 0x4E800020");
}
