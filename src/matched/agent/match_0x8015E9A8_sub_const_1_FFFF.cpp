/* 44-byte wrapper at 0x8015E9A8: calls with constants (1, 0xFFFF) */

extern void target_8015E9A8(int, unsigned int);

void sub_8015E9A8(void) {
    target_8015E9A8(1, 0xFFFF);
}
