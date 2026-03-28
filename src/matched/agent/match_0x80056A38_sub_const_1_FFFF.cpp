/* 44-byte wrapper at 0x80056A38: calls with constants (1, 0xFFFF) */

extern void target_80056A38(int, unsigned int);

void sub_80056A38(void) {
    target_80056A38(1, 0xFFFF);
}
