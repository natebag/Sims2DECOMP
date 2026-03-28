/* 44-byte wrapper at 0x802FABF8: calls with constants (1, 0xFFFF) */

extern void target_802FABF8(int, unsigned int);

void sub_802FABF8(void) {
    target_802FABF8(1, 0xFFFF);
}
