/* 44-byte wrapper at 0x800063A0: calls with constants (1, 0xFFFF) */

extern void target_800063A0(int, unsigned int);

void sub_800063A0(void) {
    target_800063A0(1, 0xFFFF);
}
