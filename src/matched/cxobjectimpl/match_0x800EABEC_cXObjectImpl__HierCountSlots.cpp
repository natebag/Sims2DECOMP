// 0x800EABEC cXObjectImpl::HierCountSlots (20B)

struct cXObj_HCS {
    char pad[0x90];
    int m_start;
    int m_end;
    int HierCountSlots();
};

int cXObj_HCS::HierCountSlots() {
    return (m_end - m_start) >> 5;
}
