/* 44-byte wrapper at 0x8002732C: calls with constants (1, 0xFFFF) */

extern void target_8002732C(int, unsigned int);

void sub_8002732C(void) {
    target_8002732C(1, 0xFFFF);
}
