/* 44-byte wrapper at 0x80138940: calls with constants (1, 0xFFFF) */

extern void target_80138940(int, unsigned int);

void sub_80138940(void) {
    target_80138940(1, 0xFFFF);
}
