// 0x8035d5cc (20B) ERotDecomp::GetBitCount(void) const
// Same pattern as EVec3Decomp::GetBitCount but + 0x23 overhead.

struct ERotDecomp {
    char pad[0x18];
    int m_numElements;
    short m_bitsPerElement;
    int GetBitCount() const;
};

int ERotDecomp::GetBitCount() const {
    return m_numElements * m_bitsPerElement + 0x23;
}
