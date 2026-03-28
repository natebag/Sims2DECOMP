/* 44-byte wrapper at 0x800A4960: calls with constants (1, 0xFFFF) */

extern void target_800A4960(int, unsigned int);

void sub_800A4960(void) {
    target_800A4960(1, 0xFFFF);
}
