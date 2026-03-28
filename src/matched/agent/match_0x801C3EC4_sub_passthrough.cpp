/* 32-byte passthrough at 0x801C3EC4 */

extern void target_801C3EC4(void);

void sub_801C3EC4(void) {
    target_801C3EC4();
}
