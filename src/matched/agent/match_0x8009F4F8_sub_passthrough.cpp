/* 32-byte passthrough at 0x8009F4F8 */

extern void target_8009F4F8(void);

void sub_8009F4F8(void) {
    target_8009F4F8();
}
