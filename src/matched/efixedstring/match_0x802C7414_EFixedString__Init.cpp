// 0x802C7414 EFixedString::Init(void *, int) (20B)

class EFixedString {
public:
    char* m_buffer;  // 0x00
    int m_maxSize;   // 0x04
    void Init(void* buf, int maxSize);
};

void EFixedString::Init(void* buf, int maxSize) {
    m_maxSize = maxSize;
    m_buffer = (char*)buf;
    m_buffer[0] = '\0';
}
