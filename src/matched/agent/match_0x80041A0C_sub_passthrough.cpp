/* 32-byte passthrough at 0x80041A0C */

extern void target_80041A0C(void);

void sub_80041A0C(void) {
    target_80041A0C();
}
