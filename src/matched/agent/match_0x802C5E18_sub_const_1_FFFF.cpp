/* 44-byte wrapper at 0x802C5E18: calls with constants (1, 0xFFFF) */

extern void target_802C5E18(int, unsigned int);

void sub_802C5E18(void) {
    target_802C5E18(1, 0xFFFF);
}
