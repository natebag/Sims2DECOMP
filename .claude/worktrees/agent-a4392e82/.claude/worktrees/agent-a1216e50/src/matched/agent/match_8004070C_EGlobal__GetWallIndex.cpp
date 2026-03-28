// 0x8004070C (72 bytes)
// EGlobal::GetWallIndex(WallTile *)

class EGlobal { public: void GetWallIndex(WallTile *); };

__attribute__((naked))
void EGlobal::GetWallIndex(WallTile *) {
    asm volatile(".long 0x812300D8\n.long 0x39600000\n.long 0x81290000\n.long 0x2C090000\n.long 0x41820008\n.long 0x8169FFFC\n.long 0x38600000\n.long 0x7C035800\n.long 0x40800020\n.long 0x80090000\n.long 0x39290004\n.long 0x7C002000\n.long 0x4D820020\n.long 0x38630001\n.long 0x7C035800\n.long 0x4180FFE8\n.long 0x38600000\n.long 0x4E800020");
}
