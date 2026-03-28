/* 44-byte wrapper at 0x802D15F8: calls with constants (1, 0xFFFF) */

extern void target_802D15F8(int, unsigned int);

void sub_802D15F8(void) {
    target_802D15F8(1, 0xFFFF);
}
