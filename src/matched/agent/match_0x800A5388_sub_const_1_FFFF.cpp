/* 44-byte wrapper at 0x800A5388: calls with constants (1, 0xFFFF) */

extern void target_800A5388(int, unsigned int);

void sub_800A5388(void) {
    target_800A5388(1, 0xFFFF);
}
