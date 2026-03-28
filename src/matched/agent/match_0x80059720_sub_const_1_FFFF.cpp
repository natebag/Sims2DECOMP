/* 44-byte wrapper at 0x80059720: calls with constants (1, 0xFFFF) */

extern void target_80059720(int, unsigned int);

void sub_80059720(void) {
    target_80059720(1, 0xFFFF);
}
