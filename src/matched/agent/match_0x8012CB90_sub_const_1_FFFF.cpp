/* 44-byte wrapper at 0x8012CB90: calls with constants (1, 0xFFFF) */

extern void target_8012CB90(int, unsigned int);

void sub_8012CB90(void) {
    target_8012CB90(1, 0xFFFF);
}
