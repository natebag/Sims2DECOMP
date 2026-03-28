/* 32-byte passthrough at 0x80053C5C */

extern void target_80053C5C(void);

void sub_80053C5C(void) {
    target_80053C5C();
}
