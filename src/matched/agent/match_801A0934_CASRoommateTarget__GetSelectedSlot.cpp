class CASRoommateTarget {
public:
    char _pad[0x90];
    int m_selectedSlot;

    int GetSelectedSlot() const;
};

int CASRoommateTarget::GetSelectedSlot() const {
    return m_selectedSlot;
}
