/* 44-byte wrapper at 0x802E1830: calls with constants (1, 0xFFFF) */

extern void target_802E1830(int, unsigned int);

void sub_802E1830(void) {
    target_802E1830(1, 0xFFFF);
}
