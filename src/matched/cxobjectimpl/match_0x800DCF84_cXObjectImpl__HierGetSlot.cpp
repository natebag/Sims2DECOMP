// 0x800DCF84 cXObjectImpl::HierGetSlot (52B)

struct Slot { char data[32]; };

struct cXObj_HGS {
    char pad[0x90];
    Slot* m_slotsStart;
    Slot* m_slotsEnd;
    Slot* HierGetSlot(int index);
};

Slot* cXObj_HGS::HierGetSlot(int index) {
    if (index >= 0) {
        unsigned int count = (unsigned int)(m_slotsEnd - m_slotsStart);
        if ((unsigned int)index < count) {
            return &m_slotsStart[index];
        }
    }
    return 0;
}
