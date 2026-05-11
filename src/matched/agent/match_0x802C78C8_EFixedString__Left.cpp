// EFixedString::Left(EFixedString&, int) const - 0x802C78C8 (116B)

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void Left(EFixedString& out, int count) const;
};

void EFixedString::Left(EFixedString& out, int count) const {
    if (this != &out) {
        int n = out.m_nMaxSize;
        if (n > count) n = count;
        memcpy(out.m_pBuffer, m_pBuffer, n);
    }
    int term = out.m_nMaxSize - 1;
    if (term > count) term = count;
    out.m_pBuffer[term] = '\0';
}
