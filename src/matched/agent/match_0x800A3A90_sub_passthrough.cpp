/* 32-byte passthrough at 0x800A3A90 */

extern void target_800A3A90(void);

void sub_800A3A90(void) {
    target_800A3A90();
}
