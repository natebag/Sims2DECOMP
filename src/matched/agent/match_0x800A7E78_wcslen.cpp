// FLAGS: -fno-schedule-insns
// 0x800A7E78 wcslen (40B)
unsigned int wcslen(unsigned short *str) {
    unsigned int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}
