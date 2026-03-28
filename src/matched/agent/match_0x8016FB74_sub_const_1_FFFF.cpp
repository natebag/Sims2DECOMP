/* 44-byte wrapper at 0x8016FB74: calls with constants (1, 0xFFFF) */

extern void target_8016FB74(int, unsigned int);

void sub_8016FB74(void) {
    target_8016FB74(1, 0xFFFF);
}
