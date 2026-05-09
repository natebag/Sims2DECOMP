// EBitArray::GetSigned(int, int) const - 0x802E0220 (128B)

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetSigned(int pos, int count) const;
    bool Get(int index) const;
    int Get(int pos, int count) const;
};

int EBitArray::GetSigned(int pos, int count) const {
    if (count) {
        int cm1 = count - 1;
        if (Get(pos + cm1)) {
            return (-1 << cm1) | Get(pos, cm1);
        }
        return Get(pos, cm1);
    }
    return 0;
}
