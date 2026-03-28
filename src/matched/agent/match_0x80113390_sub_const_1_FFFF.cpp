/* 44-byte wrapper at 0x80113390: calls with constants (1, 0xFFFF) */

extern void target_80113390(int, unsigned int);

void sub_80113390(void) {
    target_80113390(1, 0xFFFF);
}
