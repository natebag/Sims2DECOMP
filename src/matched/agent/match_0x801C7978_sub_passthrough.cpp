/* 32-byte passthrough at 0x801C7978 */

extern void target_801C7978(void);

void sub_801C7978(void) {
    target_801C7978();
}
