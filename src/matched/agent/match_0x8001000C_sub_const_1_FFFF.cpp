/* 44-byte wrapper at 0x8001000C: calls with constants (1, 0xFFFF) */

extern void target_8001000C(int, unsigned int);

void sub_8001000C(void) {
    target_8001000C(1, 0xFFFF);
}
