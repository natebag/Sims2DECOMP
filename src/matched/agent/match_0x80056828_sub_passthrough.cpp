/* 32-byte passthrough at 0x80056828 */

extern void target_80056828(void);

void sub_80056828(void) {
    target_80056828();
}
