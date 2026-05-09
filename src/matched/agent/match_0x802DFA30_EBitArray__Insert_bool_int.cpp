// EBitArray::Insert(bool, int) - 0x802DFA30 (76B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void Insert(bool val, int pos);
    void InsertElements(int pos, int count);
    void Set(int idx, bool value);
};

void EBitArray::Insert(bool val, int pos) {
    InsertElements(pos, 1);
    Set(pos, val);
}
