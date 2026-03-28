/* 44-byte wrapper at 0x801E70D0: calls with constants (1, 0xFFFF) */

extern void target_801E70D0(int, unsigned int);

void sub_801E70D0(void) {
    target_801E70D0(1, 0xFFFF);
}
