/* 44-byte wrapper at 0x8010FD28: calls with constants (1, 0xFFFF) */

extern void target_8010FD28(int, unsigned int);

void sub_8010FD28(void) {
    target_8010FD28(1, 0xFFFF);
}
