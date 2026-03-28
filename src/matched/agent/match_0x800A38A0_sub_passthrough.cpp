/* 32-byte passthrough at 0x800A38A0 */

extern void target_800A38A0(void);

void sub_800A38A0(void) {
    target_800A38A0();
}
