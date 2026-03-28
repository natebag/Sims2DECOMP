struct EStr_CTB {
    char* m_buf;
    void ConvertToBackslashes();
};

void EStr_CTB::ConvertToBackslashes() {
    char* str = m_buf;
    while (*str) {
        if (*str == '/') {
            *str = '\\';
        }
        str++;
    }
}
