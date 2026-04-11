/* auto at 0x800CC6A4 (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_800CC6A4(int a, unsigned short b);

void global_dtor_800CC6A4(void) {
    cleanup_800CC6A4(0, 0xFFFF);
}
