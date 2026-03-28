/* 44-byte wrapper at 0x802061F8: calls with constants (1, 0xFFFF) */

extern void target_802061F8(int, unsigned int);

void sub_802061F8(void) {
    target_802061F8(1, 0xFFFF);
}
