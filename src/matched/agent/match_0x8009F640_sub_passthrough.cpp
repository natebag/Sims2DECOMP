/* 32-byte passthrough at 0x8009F640 */

extern void target_8009F640(void);

void sub_8009F640(void) {
    target_8009F640();
}
