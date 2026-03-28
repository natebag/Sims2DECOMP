/* 44-byte wrapper at 0x80089080: calls with constants (1, 0xFFFF) */

extern void target_80089080(int, unsigned int);

void sub_80089080(void) {
    target_80089080(1, 0xFFFF);
}
