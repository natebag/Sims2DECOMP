// FLAGS: -fno-schedule-insns
// 0x802E05A0 EBitArray::GetAllocByteCount (36B)
// if m_data==0 return 0; else ((m_numBits+31)>>5)<<2  (word count * 4 bytes)
struct EBitArray {
    void* m_data;           // 0x0
    unsigned m_numBits;     // 0x4
    unsigned GetAllocByteCount();
};

unsigned EBitArray::GetAllocByteCount() {
    return m_data ? (((m_numBits + 31) >> 5) << 2) : 0;
}
