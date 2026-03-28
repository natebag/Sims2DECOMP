void ConvertToBackslashes_s(char* str) {
    while (*str) {
        if (*str == '/') {
            *str = '\\';
        }
        str++;
    }
}
