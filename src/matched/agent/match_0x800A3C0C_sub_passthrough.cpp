/* 32-byte passthrough at 0x800A3C0C */

extern void target_800A3C0C(void);

void sub_800A3C0C(void) {
    target_800A3C0C();
}
