// EBitArray::Set(int, bool) - 0x802DF7C0 (60B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    void Set(int idx, bool value);
};

void EBitArray::Set(int idx, bool value) {
    unsigned int wordOffset = ((unsigned int)idx >> 3) & ~3u;
    int* buf = m_pBuffer;
    int mask = 1 << (idx & 31);
    if (value)
        *(int*)((char*)buf + wordOffset) |= mask;
    else
        *(int*)((char*)buf + wordOffset) &= ~mask;
}
