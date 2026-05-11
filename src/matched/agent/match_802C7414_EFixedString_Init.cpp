// EFixedString::Init(void*, int) - 0x802C7414 (20B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void Init(void* buf, int size);
};

void EFixedString::Init(void* buf, int size) {
    m_nMaxSize = size;
    m_pBuffer = (char*)buf;
    m_pBuffer[0] = '\0';
}
