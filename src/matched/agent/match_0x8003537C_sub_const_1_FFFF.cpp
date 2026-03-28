/* 44-byte wrapper at 0x8003537C: calls with constants (1, 0xFFFF) */

extern void target_8003537C(int, unsigned int);

void sub_8003537C(void) {
    target_8003537C(1, 0xFFFF);
}
