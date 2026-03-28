/* 32-byte passthrough at 0x801C7938 */

extern void target_801C7938(void);

void sub_801C7938(void) {
    target_801C7938();
}
