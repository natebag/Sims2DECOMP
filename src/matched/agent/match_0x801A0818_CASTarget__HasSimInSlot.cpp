// 0x801A0818 (40B) CASTarget::HasSimInSlot(int) const
// Bit-test on 4-slot mask at offset +0x1348.

struct CASTarget {
    char _pad[0x1348];
    unsigned int m_simMask;
    bool HasSimInSlot(int slot) const;
};

bool CASTarget::HasSimInSlot(int slot) const {
    return (m_simMask >> (slot % 4)) & 1;
}
