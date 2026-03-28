/* 44-byte wrapper at 0x800AD1B4: calls with constants (1, 0xFFFF) */

extern void target_800AD1B4(int, unsigned int);

void sub_800AD1B4(void) {
    target_800AD1B4(1, 0xFFFF);
}
