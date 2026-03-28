class CASTarget {
public:
    char _pad[0x1348];
    unsigned int m_simSlotBits;

    void SetHasSimInSlot(int slot, int hasIt);
};

void CASTarget::SetHasSimInSlot(int slot, int hasIt) {
    int bit = slot % 4;
    if (hasIt) {
        m_simSlotBits |= (1 << bit);
    } else {
        m_simSlotBits &= ~(1 << bit);
    }
}
