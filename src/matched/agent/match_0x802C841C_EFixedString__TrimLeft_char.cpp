// EFixedString::TrimLeft(char) - 0x802C841C (92B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void MakeCopy(char* s);
    EFixedString* TrimLeft(char from);
};

EFixedString* EFixedString::TrimLeft(char from) {
    char* p = m_pBuffer;
    char c = *p;
    if (c == from) {
        do {
            c = *++p;
        } while (c == from);
        MakeCopy(p);
    }
    return this;
}
