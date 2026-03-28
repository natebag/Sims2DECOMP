/* 44-byte wrapper at 0x80077554: calls with constants (1, 0xFFFF) */

extern void target_80077554(int, unsigned int);

void sub_80077554(void) {
    target_80077554(1, 0xFFFF);
}
