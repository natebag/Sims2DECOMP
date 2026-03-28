// 0x801D4F88 (64 bytes)
// filter_wallpaper(WallTile *)

__attribute__((naked))
void filter_wallpaper(WallTile *) {
    asm volatile(".long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3D208047\n.long 0x8009618C\n.long 0x2C000000\n.long 0x4182000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x88030010\n.long 0x38600001\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600000\n.long 0x4E800020");
}
