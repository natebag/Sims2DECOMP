/* 44-byte wrapper at 0x8001501C: calls with constants (1, 0xFFFF) */

extern void target_8001501C(int, unsigned int);

void sub_8001501C(void) {
    target_8001501C(1, 0xFFFF);
}
