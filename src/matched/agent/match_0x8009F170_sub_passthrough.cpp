/* 32-byte passthrough at 0x8009F170 */

extern void target_8009F170(void);

void sub_8009F170(void) {
    target_8009F170();
}
