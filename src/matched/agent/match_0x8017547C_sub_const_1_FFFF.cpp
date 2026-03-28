/* 44-byte wrapper at 0x8017547C: calls with constants (1, 0xFFFF) */

extern void target_8017547C(int, unsigned int);

void sub_8017547C(void) {
    target_8017547C(1, 0xFFFF);
}
