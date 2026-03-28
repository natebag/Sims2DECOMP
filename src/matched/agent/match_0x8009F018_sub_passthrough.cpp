/* 32-byte passthrough at 0x8009F018 */

extern void target_8009F018(void);

void sub_8009F018(void) {
    target_8009F018();
}
