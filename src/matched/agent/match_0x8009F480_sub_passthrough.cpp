/* 32-byte passthrough at 0x8009F480 */

extern void target_8009F480(void);

void sub_8009F480(void) {
    target_8009F480();
}
