/* 44-byte wrapper at 0x80054984: calls with constants (1, 0xFFFF) */

extern void target_80054984(int, unsigned int);

void sub_80054984(void) {
    target_80054984(1, 0xFFFF);
}
