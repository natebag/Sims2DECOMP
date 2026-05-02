// EBitArray::Get(int) const - 0x802DF780 (64 bytes)
//
// Targeted as anti_tail_merge N=2 candidate. **Pure source-coax sufficed —
// no asmproc directive needed.** GCC naturally emits split-tail layout when:
//   1. Bounds check uses `if (index < m_nSize) { body } return false;` (positive
//      form with body inside the if-block) — NOT `if (index >= m_nSize) return false;`
//   2. Inner bit-test uses early-return: `if (word & mask) return true; return false;`
//   3. Critical: `mask` computed BEFORE `word` so reg-allocator assigns
//      bit_pos→r9, byte_offset→r11 (DOL ordering).
//
// Findings for MutatorSmith catalog discussion: anti_tail_merge directive may
// have been over-engineered for AptArray::get if source-coax was available.
// Worth re-checking AptArray::get with this structural pattern before promoting
// the directive to permanent catalog status.
//
// FLAGS: -msdata=eabi -G 8

struct EBitArray {
    int* m_pBuffer;
    int m_nSize;
    int m_nAllocSize;
    int m_field_C;
    void** _vtable;

    bool Get(int index) const;
};

bool EBitArray::Get(int index) const {
    if (index < m_nSize) {
        unsigned int u = (unsigned int)index;
        unsigned int mask = 1u << (u & 31);
        unsigned int word = (unsigned int)m_pBuffer[u >> 5];
        if (word & mask) return true;
        return false;
    }
    return false;
}
