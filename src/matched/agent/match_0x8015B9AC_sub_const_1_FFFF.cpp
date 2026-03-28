/* 44-byte wrapper at 0x8015B9AC: calls with constants (1, 0xFFFF) */

extern void target_8015B9AC(int, unsigned int);

void sub_8015B9AC(void) {
    target_8015B9AC(1, 0xFFFF);
}
