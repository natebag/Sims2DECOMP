/* 32-byte passthrough at 0x8015BA5C */

extern void target_8015BA5C(void);

void sub_8015BA5C(void) {
    target_8015BA5C();
}
