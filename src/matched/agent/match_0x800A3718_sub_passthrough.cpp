/* 32-byte passthrough at 0x800A3718 */

extern void target_800A3718(void);

void sub_800A3718(void) {
    target_800A3718();
}
