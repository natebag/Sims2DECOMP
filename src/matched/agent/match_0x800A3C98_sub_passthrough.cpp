/* 32-byte passthrough at 0x800A3C98 */

extern void target_800A3C98(void);

void sub_800A3C98(void) {
    target_800A3C98();
}
