/* 44-byte wrapper at 0x802D6F24: calls with constants (1, 0xFFFF) */

extern void target_802D6F24(int, unsigned int);

void sub_802D6F24(void) {
    target_802D6F24(1, 0xFFFF);
}
