/* 44-byte wrapper at 0x800A0034: calls with constants (1, 0xFFFF) */

extern void target_800A0034(int, unsigned int);

void sub_800A0034(void) {
    target_800A0034(1, 0xFFFF);
}
