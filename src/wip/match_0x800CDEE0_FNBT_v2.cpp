// FLAGS: -fno-schedule-insns
// NeighborhoodImpl::FindNeighborByType(ObjSelector *) - 0x800CDEE0 (80 bytes)

struct ElemFNBT {
    char pad[12];
    void* m_type;  // offset 0xC
};

struct NeighborhoodFNBT {
    char pad0x74[0x74];
    ElemFNBT** m_begin;  // offset 0x74 = 116
    ElemFNBT** m_end;    // offset 0x78 = 120
    ElemFNBT* FindNeighborByType(void* selector);
};

ElemFNBT* NeighborhoodFNBT::FindNeighborByType(void* selector) {
    ElemFNBT* result = 0;
    ElemFNBT** iter = m_begin;
    if (iter == m_end) return result;
    ElemFNBT** iend = m_end;
    do {
        ElemFNBT* elem = *iter;
        if (elem) {
            if (elem->m_type == selector && !result) {
                result = elem;
            }
        }
        iter++;
    } while (iter != iend);
    return result;
}
