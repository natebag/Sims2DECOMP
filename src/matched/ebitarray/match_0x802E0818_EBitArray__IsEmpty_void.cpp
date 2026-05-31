// FLAGS: -fno-schedule-insns
// 0x802E0818 EBitArray::IsEmpty(void) (16B)
// lwz r3,4(r3); subfic r0,r3,0; adde r3,r0,r3; blr  -- (m_numBits == 0)
struct EBitArray {
    void* m_data;           // 0x0
    unsigned m_numBits;     // 0x4
    int IsEmpty();
};

int EBitArray::IsEmpty() {
    return m_numBits == 0;
}
