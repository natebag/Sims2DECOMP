/* 32-byte passthrough at 0x80054390 */

extern void target_80054390(void);

void sub_80054390(void) {
    target_80054390();
}
