unsigned int wcslen(unsigned short *str) {
    unsigned int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}
