/* 44-byte wrapper at 0x8021F0EC: calls with constants (1, 0xFFFF) */

extern void target_8021F0EC(int, unsigned int);

void sub_8021F0EC(void) {
    target_8021F0EC(1, 0xFFFF);
}
