/* 44-byte wrapper at 0x80014B70: calls with constants (1, 0xFFFF) */

extern void target_80014B70(int, unsigned int);

void sub_80014B70(void) {
    target_80014B70(1, 0xFFFF);
}
