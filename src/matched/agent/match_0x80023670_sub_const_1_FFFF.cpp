/* 44-byte wrapper at 0x80023670: calls with constants (1, 0xFFFF) */

extern void target_80023670(int, unsigned int);

void sub_80023670(void) {
    target_80023670(1, 0xFFFF);
}
