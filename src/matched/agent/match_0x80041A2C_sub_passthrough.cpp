/* 32-byte passthrough at 0x80041A2C */

extern void target_80041A2C(void);

void sub_80041A2C(void) {
    target_80041A2C();
}
