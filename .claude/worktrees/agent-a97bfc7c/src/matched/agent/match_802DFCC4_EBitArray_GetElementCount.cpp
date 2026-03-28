// 0x802DFCC4 (16 bytes) - EBitArray::GetElementCount(void) const
// lwz r3, 4(r3); addi r3, r3, 31; srwi r3, r3, 5; blr  =>  (m_bitCount + 31) / 32

struct EBitArray_GEC {
    char pad[0x04];
    int m_bitCount;
    int GetElementCount() const;
};
int EBitArray_GEC::GetElementCount() const {
    return (unsigned)(m_bitCount + 31) >> 5;
}
