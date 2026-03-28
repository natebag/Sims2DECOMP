/* 44-byte wrapper at 0x802C4A30: calls with constants (1, 0xFFFF) */

extern void target_802C4A30(int, unsigned int);

void sub_802C4A30(void) {
    target_802C4A30(1, 0xFFFF);
}
