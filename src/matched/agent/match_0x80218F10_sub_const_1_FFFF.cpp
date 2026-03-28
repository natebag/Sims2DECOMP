/* 44-byte wrapper at 0x80218F10: calls with constants (1, 0xFFFF) */

extern void target_80218F10(int, unsigned int);

void sub_80218F10(void) {
    target_80218F10(1, 0xFFFF);
}
