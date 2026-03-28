/* 32-byte passthrough at 0x80054068 */

extern void target_80054068(void);

void sub_80054068(void) {
    target_80054068();
}
