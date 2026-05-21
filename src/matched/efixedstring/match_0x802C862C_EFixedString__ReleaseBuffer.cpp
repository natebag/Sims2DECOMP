// 0x802C862C EFixedString::ReleaseBuffer(void) (4B)

class EFixedString {
public:
    char* m_buffer;  // 0x00
    int m_maxSize;   // 0x04
    void ReleaseBuffer();
};

void EFixedString::ReleaseBuffer() {
}
