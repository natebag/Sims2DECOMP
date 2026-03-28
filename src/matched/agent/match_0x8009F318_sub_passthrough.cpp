/* 32-byte passthrough at 0x8009F318 */

extern void target_8009F318(void);

void sub_8009F318(void) {
    target_8009F318();
}
