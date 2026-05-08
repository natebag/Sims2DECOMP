// EFixedString::GetBuffer(int) - 0x802C8610 (28B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    char* GetBuffer(int n);
};

char* EFixedString::GetBuffer(int n) {
    if (n <= m_nMaxSize) return m_pBuffer;
    return 0;
}
