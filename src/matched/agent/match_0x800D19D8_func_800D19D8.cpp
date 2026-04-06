/* auto at 0x800D19D8 (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_800D19D8(int a, unsigned short b);

void global_dtor_800D19D8(void) {
    cleanup_800D19D8(0, 0xFFFF);
}
