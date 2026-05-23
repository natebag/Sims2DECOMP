// EBitArray::Remove(int, int) - 0x802DFBF0 (124B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void Remove(int pos, int count);
    bool Get(int index) const;
    void Set(int idx, bool value);
};

void EBitArray::Remove(int pos, int count) {
    int end = pos + count;
    int copyCount = m_nSize - end;
    for (int i = 0; i < copyCount; i++) {
        bool bit = Get(end + i);
        Set(pos + i, bit);
    }
    m_nSize -= count;
}
