/* 44-byte wrapper at 0x801759B8: calls with constants (1, 0xFFFF) */

extern void target_801759B8(int, unsigned int);

void sub_801759B8(void) {
    target_801759B8(1, 0xFFFF);
}
