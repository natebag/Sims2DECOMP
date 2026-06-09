/* 32-byte passthrough at 0x8015BA8C */

extern void target_8015BA8C(void);

void sub_8015BA8C(void) {
    target_8015BA8C();
}
