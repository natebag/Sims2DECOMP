/* 32-byte passthrough at 0x8005B1AC */

extern void target_8005B1AC(void);

void sub_8005B1AC(void) {
    target_8005B1AC();
}
