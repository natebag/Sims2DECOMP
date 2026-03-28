/* 44-byte wrapper at 0x802D5CB8: calls with constants (1, 0xFFFF) */

extern void target_802D5CB8(int, unsigned int);

void sub_802D5CB8(void) {
    target_802D5CB8(1, 0xFFFF);
}
