/* 44-byte wrapper at 0x802F9B50: calls with constants (1, 0xFFFF) */

extern void target_802F9B50(int, unsigned int);

void sub_802F9B50(void) {
    target_802F9B50(1, 0xFFFF);
}
