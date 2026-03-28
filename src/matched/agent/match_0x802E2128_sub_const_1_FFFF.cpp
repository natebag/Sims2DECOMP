/* 44-byte wrapper at 0x802E2128: calls with constants (1, 0xFFFF) */

extern void target_802E2128(int, unsigned int);

void sub_802E2128(void) {
    target_802E2128(1, 0xFFFF);
}
