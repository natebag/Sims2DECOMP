/* 44-byte wrapper at 0x80095A78: calls with constants (1, 0xFFFF) */

extern void target_80095A78(int, unsigned int);

void sub_80095A78(void) {
    target_80095A78(1, 0xFFFF);
}
