// EFixedString::TrimLeft(char*) - 0x802C8550 (128B)

extern "C" char* strchr(const char* s, int c);

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void MakeCopy(char* s);
    EFixedString* TrimLeft(char* charset);
};

EFixedString* EFixedString::TrimLeft(char* charset) {
    if (strchr(charset, m_pBuffer[0])) {
        char* p = m_pBuffer + 1;
        while (strchr(charset, *p)) p++;
        MakeCopy(p);
    }
    return this;
}
