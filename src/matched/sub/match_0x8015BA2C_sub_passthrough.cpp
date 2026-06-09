/* 32-byte passthrough at 0x8015BA2C */

extern void target_8015BA2C(void);

void sub_8015BA2C(void) {
    target_8015BA2C();
}
