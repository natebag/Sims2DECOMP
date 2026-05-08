// EBitArray::operator&=(EBitArray&) - 0x802DFD3C (104B)
// FLAGS: -fno-schedule-insns

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetElementCount() const;
    void operator&=(EBitArray& other);
};

void EBitArray::operator&=(EBitArray& other) {
    int count = GetElementCount();
    int* dst = m_pBuffer;
    int i = count - 1;
    int* src = other.m_pBuffer;
    if (!count) return;
    do {
        *dst &= *src;
        src++;
        dst++;
    } while (i-- != 0);
}
