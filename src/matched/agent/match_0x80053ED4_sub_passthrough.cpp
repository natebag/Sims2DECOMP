/* 32-byte passthrough at 0x80053ED4 */

extern void target_80053ED4(void);

void sub_80053ED4(void) {
    target_80053ED4();
}
