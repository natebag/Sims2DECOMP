// EBitArray::SetGrowBy(int) - 0x802DF8DC (16B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void SetGrowBy(int growBy);
};

void EBitArray::SetGrowBy(int growBy) {
    m_field_C = (growBy + 31) & ~31;
}
