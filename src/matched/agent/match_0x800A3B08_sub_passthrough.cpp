/* 32-byte passthrough at 0x800A3B08 */

extern void target_800A3B08(void);

void sub_800A3B08(void) {
    target_800A3B08();
}
