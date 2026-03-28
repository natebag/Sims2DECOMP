/* 32-byte passthrough at 0x800756BC */

extern void target_800756BC(void);

void sub_800756BC(void) {
    target_800756BC();
}
