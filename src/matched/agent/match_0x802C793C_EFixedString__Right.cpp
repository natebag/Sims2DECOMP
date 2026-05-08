// EFixedString::Right(EFixedString*, int) - 0x802C793C (80B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int GetLength() const;
    void MakeCopy(char* s);
    void Right(EFixedString* dest, int count);
};

void EFixedString::Right(EFixedString* dest, int count) {
    int offset = GetLength() - count;
    if (offset < 0) offset = 0;
    dest->MakeCopy(m_pBuffer + offset);
}
