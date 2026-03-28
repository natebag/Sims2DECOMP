/* 32-byte passthrough at 0x801C7958 */

extern void target_801C7958(void);

void sub_801C7958(void) {
    target_801C7958();
}
