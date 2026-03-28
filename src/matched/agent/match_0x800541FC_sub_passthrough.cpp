/* 32-byte passthrough at 0x800541FC */

extern void target_800541FC(void);

void sub_800541FC(void) {
    target_800541FC();
}
