// 0x801D514C (84 bytes)
// filter_floor(int, unsigned int, FloorTile *)

__attribute__((naked))
void filter_floor(int, unsigned int, FloorTile *) {
    asm volatile(".long 0x7CA52B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3D208047\n.long 0x8009618C\n.long 0x2C000000\n.long 0x4182000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x2C030000\n.long 0x4182FFDC\n.long 0x8005000C\n.long 0x7C002000\n.long 0x4182FFD0\n.long 0x88050014\n.long 0x38600001\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600000\n.long 0x4E800020");
}
