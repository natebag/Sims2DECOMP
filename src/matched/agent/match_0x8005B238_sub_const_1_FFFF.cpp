/* 44-byte wrapper at 0x8005B238: calls with constants (1, 0xFFFF) */

extern void target_8005B238(int, unsigned int);

void sub_8005B238(void) {
    target_8005B238(1, 0xFFFF);
}
