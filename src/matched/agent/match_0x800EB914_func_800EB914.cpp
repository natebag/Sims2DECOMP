/* auto at 0x800EB914 (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_800EB914(int a, unsigned short b);

void global_dtor_800EB914(void) {
    cleanup_800EB914(0, 0xFFFF);
}
