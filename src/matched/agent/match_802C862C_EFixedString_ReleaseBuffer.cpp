// EFixedString::ReleaseBuffer() - 0x802C862C (4B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void ReleaseBuffer();
};

void EFixedString::ReleaseBuffer() {
}
