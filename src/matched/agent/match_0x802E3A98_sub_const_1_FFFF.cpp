/* 44-byte wrapper at 0x802E3A98: calls with constants (1, 0xFFFF) */

extern void target_802E3A98(int, unsigned int);

void sub_802E3A98(void) {
    target_802E3A98(1, 0xFFFF);
}
