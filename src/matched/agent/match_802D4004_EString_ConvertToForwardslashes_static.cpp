void ConvertToForwardslashes_s(char* str) {
    while (*str) {
        if (*str == '\\') {
            *str = '/';
        }
        str++;
    }
}
