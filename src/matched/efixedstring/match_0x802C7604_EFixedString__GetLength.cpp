// 0x802C7604 EFixedString::GetLength(void) const (36B)

int strlen(const char*);

class EFixedString {
public:
    char* m_buffer;  // 0x00
    int m_maxSize;   // 0x04
    int GetLength() const;
};

int EFixedString::GetLength() const {
    return strlen(m_buffer);
}
