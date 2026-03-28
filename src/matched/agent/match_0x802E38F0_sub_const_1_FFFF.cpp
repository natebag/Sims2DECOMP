/* 44-byte wrapper at 0x802E38F0: calls with constants (1, 0xFFFF) */

extern void target_802E38F0(int, unsigned int);

void sub_802E38F0(void) {
    target_802E38F0(1, 0xFFFF);
}
