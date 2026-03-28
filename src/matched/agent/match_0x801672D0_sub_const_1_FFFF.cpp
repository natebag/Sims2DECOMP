/* 44-byte wrapper at 0x801672D0: calls with constants (1, 0xFFFF) */

extern void target_801672D0(int, unsigned int);

void sub_801672D0(void) {
    target_801672D0(1, 0xFFFF);
}
