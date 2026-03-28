/* 44-byte wrapper at 0x80134A34: calls with constants (1, 0xFFFF) */

extern void target_80134A34(int, unsigned int);

void sub_80134A34(void) {
    target_80134A34(1, 0xFFFF);
}
