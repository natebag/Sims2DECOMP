/* 44-byte wrapper at 0x800B1394: calls with constants (1, 0xFFFF) */

extern void target_800B1394(int, unsigned int);

void sub_800B1394(void) {
    target_800B1394(1, 0xFFFF);
}
