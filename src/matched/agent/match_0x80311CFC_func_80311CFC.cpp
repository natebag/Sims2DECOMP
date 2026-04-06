/* auto at 0x80311CFC (44B) [global_destructors_44B] */

// FLAGS: -fno-elide-constructors
extern void cleanup_80311CFC(int a, unsigned short b);

void global_dtor_80311CFC(void) {
    cleanup_80311CFC(0, 0xFFFF);
}
