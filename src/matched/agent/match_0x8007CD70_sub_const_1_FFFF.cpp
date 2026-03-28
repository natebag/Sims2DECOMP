/* 44-byte wrapper at 0x8007CD70: calls with constants (1, 0xFFFF) */

extern void target_8007CD70(int, unsigned int);

void sub_8007CD70(void) {
    target_8007CD70(1, 0xFFFF);
}
