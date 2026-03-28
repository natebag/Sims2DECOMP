/* 32-byte passthrough at 0x801C6FA4 */

extern void target_801C6FA4(void);

void sub_801C6FA4(void) {
    target_801C6FA4();
}
