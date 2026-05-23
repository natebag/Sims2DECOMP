// EBitArray::FreeUnusedBufferSpace() - 0x802E0744 (40B)
// FLAGS: -fno-schedule-insns

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void FreeUnusedBufferSpace();
    void SetSize(int, int);
};

void EBitArray::FreeUnusedBufferSpace() {
    SetSize(m_nSize, 0);
}
