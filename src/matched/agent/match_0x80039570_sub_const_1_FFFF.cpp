/* 44-byte wrapper at 0x80039570: calls with constants (1, 0xFFFF) */

extern void target_80039570(int, unsigned int);

void sub_80039570(void) {
    target_80039570(1, 0xFFFF);
}
