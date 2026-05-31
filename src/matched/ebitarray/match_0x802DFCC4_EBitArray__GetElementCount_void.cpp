// FLAGS: -fno-schedule-insns
// 0x802DFCC4 EBitArray::GetElementCount(void) (16B)
// lwz r3,4(r3); addi r3,r3,31; srwi r3,r3,5; blr  -- words = (bits+31)/32
struct EBitArray {
    void* m_data;           // 0x0
    unsigned m_numBits;     // 0x4
    unsigned GetElementCount();
};

unsigned EBitArray::GetElementCount() {
    return (m_numBits + 31) >> 5;
}
