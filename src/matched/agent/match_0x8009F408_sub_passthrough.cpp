/* 32-byte passthrough at 0x8009F408 */

extern void target_8009F408(void);

void sub_8009F408(void) {
    target_8009F408();
}
