/* 44-byte wrapper at 0x80011E94: calls with constants (1, 0xFFFF) */

extern void target_80011E94(int, unsigned int);

void sub_80011E94(void) {
    target_80011E94(1, 0xFFFF);
}
