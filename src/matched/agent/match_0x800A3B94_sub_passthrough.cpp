/* 32-byte passthrough at 0x800A3B94 */

extern void target_800A3B94(void);

void sub_800A3B94(void) {
    target_800A3B94();
}
