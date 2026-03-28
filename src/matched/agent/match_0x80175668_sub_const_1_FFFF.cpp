/* 44-byte wrapper at 0x80175668: calls with constants (1, 0xFFFF) */

extern void target_80175668(int, unsigned int);

void sub_80175668(void) {
    target_80175668(1, 0xFFFF);
}
