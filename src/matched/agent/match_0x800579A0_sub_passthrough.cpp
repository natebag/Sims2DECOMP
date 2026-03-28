/* 32-byte passthrough at 0x800579A0 */

extern void target_800579A0(void);

void sub_800579A0(void) {
    target_800579A0();
}
