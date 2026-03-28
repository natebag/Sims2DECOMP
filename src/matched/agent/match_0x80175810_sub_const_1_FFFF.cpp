/* 44-byte wrapper at 0x80175810: calls with constants (1, 0xFFFF) */

extern void target_80175810(int, unsigned int);

void sub_80175810(void) {
    target_80175810(1, 0xFFFF);
}
