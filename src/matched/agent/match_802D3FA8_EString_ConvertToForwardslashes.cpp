struct EStr_CTF {
    char* m_buf;
    void ConvertToForwardslashes();
};

void EStr_CTF::ConvertToForwardslashes() {
    char* str = m_buf;
    while (*str) {
        if (*str == '\\') {
            *str = '/';
        }
        str++;
    }
}
