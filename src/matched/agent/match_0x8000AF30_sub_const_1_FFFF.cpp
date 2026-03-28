/* 44-byte wrapper at 0x8000AF30: calls with constants (1, 0xFFFF) */

extern void target_8000AF30(int, unsigned int);

void sub_8000AF30(void) {
    target_8000AF30(1, 0xFFFF);
}
