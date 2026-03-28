/* 32-byte passthrough at 0x801C6F84 */

extern void target_801C6F84(void);

void sub_801C6F84(void) {
    target_801C6F84();
}
