class CASTarget {
public:
    char _pad[0x1348];
    unsigned int m_simSlotBits;

    int HasSimInSlot(int slot) const;
};

int CASTarget::HasSimInSlot(int slot) const {
    int bit = slot % 4;
    return (m_simSlotBits >> bit) & 1;
}
