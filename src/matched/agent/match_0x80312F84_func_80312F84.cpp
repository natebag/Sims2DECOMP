/* auto at 0x80312F84 (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_80312F84(int a, unsigned short b);

void global_dtor_80312F84(void) {
    cleanup_80312F84(0, 0xFFFF);
}
