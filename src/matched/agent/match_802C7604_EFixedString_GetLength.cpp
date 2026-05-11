// EFixedString::GetLength() const - 0x802C7604 (36B)

extern "C" unsigned int strlen(const char* s);

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
};

int EFixedString::GetLength() const {
    return strlen(m_pBuffer);
}
