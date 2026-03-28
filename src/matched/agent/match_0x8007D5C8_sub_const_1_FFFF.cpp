/* 44-byte wrapper at 0x8007D5C8: calls with constants (1, 0xFFFF) */

extern void target_8007D5C8(int, unsigned int);

void sub_8007D5C8(void) {
    target_8007D5C8(1, 0xFFFF);
}
