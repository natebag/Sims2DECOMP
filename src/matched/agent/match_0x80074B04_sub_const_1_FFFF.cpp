/* 44-byte wrapper at 0x80074B04: calls with constants (1, 0xFFFF) */

extern void target_80074B04(int, unsigned int);

void sub_80074B04(void) {
    target_80074B04(1, 0xFFFF);
}
