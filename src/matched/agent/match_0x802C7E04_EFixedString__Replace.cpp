// EFixedString::Replace(char, char) - 0x802C7E04 (48B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void Replace(char from, char to);
};

void EFixedString::Replace(char from, char to) {
    char* p = m_pBuffer;
    unsigned char c = *p;
    if (!c) return;
    do {
        if ((signed char)c == from) *p = to;
        c = *++p;
    } while (c);
}
