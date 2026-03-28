/* 44-byte wrapper at 0x80042BEC: calls with constants (1, 0xFFFF) */

extern void target_80042BEC(int, unsigned int);

void sub_80042BEC(void) {
    target_80042BEC(1, 0xFFFF);
}
