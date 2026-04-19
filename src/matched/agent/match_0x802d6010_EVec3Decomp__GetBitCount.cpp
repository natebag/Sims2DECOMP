// 0x802d6010 (20B) EVec3Decomp::GetBitCount(void) const
// lha r0, 0x1C(r3) — bitsPerElement is signed short; + 0xE3 overhead bytes.

struct EVec3Decomp {
    char pad[0x18];
    int m_numElements;
    short m_bitsPerElement;
    int GetBitCount() const;
};

int EVec3Decomp::GetBitCount() const {
    return m_numElements * m_bitsPerElement + 0xe3;
}
