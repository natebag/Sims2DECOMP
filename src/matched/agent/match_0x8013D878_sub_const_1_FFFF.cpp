/* 44-byte wrapper at 0x8013D878: calls with constants (1, 0xFFFF) */

extern void target_8013D878(int, unsigned int);

void sub_8013D878(void) {
    target_8013D878(1, 0xFFFF);
}
