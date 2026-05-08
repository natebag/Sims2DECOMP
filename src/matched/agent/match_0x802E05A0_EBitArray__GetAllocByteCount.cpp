// EBitArray::GetAllocByteCount(void) - 0x802E05A0 (36B)
// FLAGS: -fno-schedule-insns
// ASMPROC_force_reg_at_pos: match="lwz 3,4(3)" pos=0 from_reg=3 to_reg=9
// ASMPROC_force_reg: match="addi 3,3,31" from_reg=3 to_reg=9
// ASMPROC_force_reg_at_pos: match="rlwinm 3,3,29,3,29" pos=1 from_reg=3 to_reg=9

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;

    int GetAllocByteCount(void);
};

int EBitArray::GetAllocByteCount(void) {
    if (!m_pBuffer) return 0;
    unsigned int n = m_nSize;
    return (int)((n + 31) / 32) * 4;
}
