// EBitArray::InvertAll(void) - 0x802DF884 (88B)
// FLAGS: -fno-schedule-insns -fno-elide-constructors

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetElementCount(void) const;
    void InvertAll(void);
};

void EBitArray::InvertAll(void) {
    int count = GetElementCount();
    int* buf = m_pBuffer;
    int i = count - 1;
    if (!count) return;
    do {
        *buf = ~*buf;
        buf++;
    } while (i-- != 0);
}
