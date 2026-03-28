/* 44-byte wrapper at 0x800373A8: calls with constants (1, 0xFFFF) */

extern void target_800373A8(int, unsigned int);

void sub_800373A8(void) {
    target_800373A8(1, 0xFFFF);
}
