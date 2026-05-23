// EBitArray::SetAll(bool) - 0x802DF7FC (136B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetElementCount() const;
    void SetAll(bool value);
};

void EBitArray::SetAll(bool value) {
    int count = GetElementCount();
    int* buf = m_pBuffer;
    if (value) {
        int i = count - 1;
        if (!count) return;
        do {
            *buf++ = -1;
        } while (i-- != 0);
    } else {
        int i = count - 1;
        if (!count) return;
        do {
            *buf++ = 0;
        } while (i-- != 0);
    }
}
