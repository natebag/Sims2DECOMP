/* auto at 0x800D9400 (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_800D9400(int a, unsigned short b);

void global_dtor_800D9400(void) {
    cleanup_800D9400(0, 0xFFFF);
}
