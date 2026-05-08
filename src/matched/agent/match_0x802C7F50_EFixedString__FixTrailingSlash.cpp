// EFixedString::FixTrailingSlash() - 0x802C7F50 (84B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    EFixedString& operator+=(char c);
    void FixTrailingSlash();
};

void EFixedString::FixTrailingSlash() {
    int len = GetLength();
    if (!len) return;
    int idx = len - 1;
    if (m_pBuffer[idx] == '\\') return;
    *this += '\\';
}
