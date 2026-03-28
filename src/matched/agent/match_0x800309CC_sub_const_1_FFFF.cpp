/* 44-byte wrapper at 0x800309CC: calls with constants (1, 0xFFFF) */

extern void target_800309CC(int, unsigned int);

void sub_800309CC(void) {
    target_800309CC(1, 0xFFFF);
}
