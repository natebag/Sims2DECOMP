// EBitArray::operator=(EBitArray&) - 0x802DFC6C (88B)

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void SetSize(int size, int flag);
    EBitArray& operator=(EBitArray& other);
};

EBitArray& EBitArray::operator=(EBitArray& other) {
    SetSize(other.m_nSize, 0);
    unsigned int n = m_nSize;
    int byteCount = (int)((n + 31) / 32) * 4;
    memcpy(m_pBuffer, other.m_pBuffer, byteCount);
    return *this;
}
