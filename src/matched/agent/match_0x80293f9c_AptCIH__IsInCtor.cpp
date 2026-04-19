// 0x80293f9c (12B) AptCIH::IsInCtor(void) const
// Extracts IBM bit 21 (standard bit 10) of the 32-bit word at 0x5C via (m_data >> 10) & 1.

struct AptCIH {
    char pad[0x5C];
    unsigned int m_data;
    int IsInCtor() const;
};

int AptCIH::IsInCtor() const {
    return (m_data >> 10) & 1;
}
