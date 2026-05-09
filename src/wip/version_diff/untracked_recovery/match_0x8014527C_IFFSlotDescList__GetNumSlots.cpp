// 0x8014527C IFFSlotDescList::GetNumSlots(void) (32B)

struct IFFSlotDescList {
    char pad[0x54];
    int m_numSlots;
    int m_field88;
    int GetNumSlots();
};

int IFFSlotDescList::GetNumSlots() {
    return (m_field88 - m_numSlots) / 9;
}
