/* 44-byte wrapper at 0x800B5194: calls with constants (1, 0xFFFF) */

extern void target_800B5194(int, unsigned int);

void sub_800B5194(void) {
    target_800B5194(1, 0xFFFF);
}
