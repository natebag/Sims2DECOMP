/* 44-byte wrapper at 0x8003E198: calls with constants (1, 0xFFFF) */

extern void target_8003E198(int, unsigned int);

void sub_8003E198(void) {
    target_8003E198(1, 0xFFFF);
}
