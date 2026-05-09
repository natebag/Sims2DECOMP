// EBitArray::Intersection(EBitArray&) const - 0x802DFE98 (116B)
// FLAGS: -fno-schedule-insns
// Use goto to force beq[return-false] instead of GCC's b[loop-condition] optimization

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetElementCount() const;
    bool Intersection(EBitArray& other) const;
};

bool EBitArray::Intersection(EBitArray& other) const {
    int count = GetElementCount();
    int* dst = m_pBuffer;
    int i = count - 1;
    int* src = other.m_pBuffer;
    if (count == 0) goto done;
    do {
        int d = *dst++;
        int s = *src++;
        if (!(d & s)) continue;
        return true;
    } while (i-- != 0);
done:
    return false;
}
