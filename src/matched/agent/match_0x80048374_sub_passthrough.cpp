/* 32-byte passthrough at 0x80048374 */

extern void target_80048374(void);

void sub_80048374(void) {
    target_80048374();
}
