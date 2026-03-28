/* 44-byte wrapper at 0x80048518: calls with constants (1, 0xFFFF) */

extern void target_80048518(int, unsigned int);

void sub_80048518(void) {
    target_80048518(1, 0xFFFF);
}
