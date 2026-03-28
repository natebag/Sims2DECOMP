/* 44-byte wrapper at 0x800B83E0: calls with constants (1, 0xFFFF) */

extern void target_800B83E0(int, unsigned int);

void sub_800B83E0(void) {
    target_800B83E0(1, 0xFFFF);
}
