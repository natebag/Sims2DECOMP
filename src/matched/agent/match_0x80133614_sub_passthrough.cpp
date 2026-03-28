/* 32-byte passthrough at 0x80133614 */

extern void target_80133614(void);

void sub_80133614(void) {
    target_80133614();
}
