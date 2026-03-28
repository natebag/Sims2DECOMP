/* 32-byte passthrough at 0x8005C76C */

extern void target_8005C76C(void);

void sub_8005C76C(void) {
    target_8005C76C();
}
