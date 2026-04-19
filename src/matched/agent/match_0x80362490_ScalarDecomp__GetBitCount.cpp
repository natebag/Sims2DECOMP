// 0x80362490 (20B) ScalarDecomp::GetBitCount(void) const
// Same pattern as EVec3Decomp::GetBitCount but + 0x63 overhead.

struct ScalarDecomp {
    char pad[0x18];
    int m_numElements;
    short m_bitsPerElement;
    int GetBitCount() const;
};

int ScalarDecomp::GetBitCount() const {
    return m_numElements * m_bitsPerElement + 0x63;
}
