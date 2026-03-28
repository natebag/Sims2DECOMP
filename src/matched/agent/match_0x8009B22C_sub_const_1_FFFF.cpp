/* 44-byte wrapper at 0x8009B22C: calls with constants (1, 0xFFFF) */

extern void target_8009B22C(int, unsigned int);

void sub_8009B22C(void) {
    target_8009B22C(1, 0xFFFF);
}
