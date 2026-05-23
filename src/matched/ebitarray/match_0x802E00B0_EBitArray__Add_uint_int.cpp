// EBitArray::Add(unsigned int, int) - 0x802E00B0 (108B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void Add(unsigned int bits, int count);
    void Insert(bool val, int pos);
};

void EBitArray::Add(unsigned int bits, int count) {
    for (int i = 0; i < count; i++) {
        unsigned int one = 1;
        Insert(bits & (one << i), m_nSize);
    }
}
