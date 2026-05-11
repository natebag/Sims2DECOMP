// EFixedString::Remove(EFixedString&, char) - 0x802C7E34 (136B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int Find(char c) const;
    void MakeCopy(char* s);
    void Remove(EFixedString& out, char from);
};

void EFixedString::Remove(EFixedString& out, char from) {
    if (Find(from) == -1) return;
    char* src = m_pBuffer;
    char* dst = out.m_pBuffer;
    unsigned char c = *src;
    if (c) {
        do {
            if ((signed char)c != from) {
                *dst = c;
                dst++;
            }
            c = *++src;
        } while (c);
    }
    *dst = '\0';
    MakeCopy(out.m_pBuffer);
}
