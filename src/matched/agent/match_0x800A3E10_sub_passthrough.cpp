/* 32-byte passthrough at 0x800A3E10 */

extern void target_800A3E10(void);

void sub_800A3E10(void) {
    target_800A3E10();
}
