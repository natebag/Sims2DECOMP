/* 44-byte wrapper at 0x8003DE7C: calls with constants (1, 0xFFFF) */

extern void target_8003DE7C(int, unsigned int);

void sub_8003DE7C(void) {
    target_8003DE7C(1, 0xFFFF);
}
