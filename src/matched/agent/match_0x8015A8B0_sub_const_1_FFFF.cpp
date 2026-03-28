/* 44-byte wrapper at 0x8015A8B0: calls with constants (1, 0xFFFF) */

extern void target_8015A8B0(int, unsigned int);

void sub_8015A8B0(void) {
    target_8015A8B0(1, 0xFFFF);
}
