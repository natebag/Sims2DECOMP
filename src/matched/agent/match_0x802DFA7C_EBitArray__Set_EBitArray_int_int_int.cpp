// EBitArray::Set(EBitArray&, int, int, int) - 0x802DFA7C (108B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void Set(EBitArray& src, int srcStart, int dstStart, int count);
    void Set(int idx, bool value);
    bool Get(int index) const;
};

void EBitArray::Set(EBitArray& src, int srcStart, int dstStart, int count) {
    for (int i = 0; i < count; i++) {
        bool bit = src.Get(srcStart + i);
        Set(dstStart + i, bit);
    }
}
