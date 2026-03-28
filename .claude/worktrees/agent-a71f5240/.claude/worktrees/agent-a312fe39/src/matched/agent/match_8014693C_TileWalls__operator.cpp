// 0x8014693C (92 bytes)
// TileWalls::operator=(TileWalls &)

class TileWalls { public: void operator=(TileWalls &); };

__attribute__((naked))
void TileWalls::operator=(TileWalls &) {
    asm volatile(".long 0x7C691B78\n.long 0x39600030\n.long 0x80040000\n.long 0x356BFFE8\n.long 0x90090000\n.long 0x80040004\n.long 0x90090004\n.long 0x80040008\n.long 0x90090008\n.long 0x8004000C\n.long 0x9009000C\n.long 0x80040010\n.long 0x90090010\n.long 0x80040014\n.long 0x38840018\n.long 0x90090014\n.long 0x39290018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x90090000\n.long 0x80040004\n.long 0x90090004\n.long 0x4E800020");
}
