/* 44-byte wrapper at 0x80070554: calls with constants (1, 0xFFFF) */

extern void target_80070554(int, unsigned int);

void sub_80070554(void) {
    target_80070554(1, 0xFFFF);
}
