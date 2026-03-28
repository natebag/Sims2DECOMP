/* 44-byte wrapper at 0x802F0D70: calls with constants (1, 0xFFFF) */

extern void target_802F0D70(int, unsigned int);

void sub_802F0D70(void) {
    target_802F0D70(1, 0xFFFF);
}
