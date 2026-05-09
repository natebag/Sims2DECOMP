// FLAGS: -fno-schedule-insns
// 0x800CDEE0 (80 bytes)
// NeighborhoodImpl::FindNeighborByType(ObjSelector *)

struct ElemFNBT {
    char pad[12];
    void* m_type;  // offset 0xC
};

struct NeighborhoodFNBT {
    char pad0x74[0x74];
    ElemFNBT** m_begin;  // offset 0x74
    ElemFNBT** m_end;    // offset 0x78
    ElemFNBT* FindNeighborByType(void* selector);
};

ElemFNBT* NeighborhoodFNBT::FindNeighborByType(void* selector) {
    void** end = (void**)m_end;
    ElemFNBT* result = 0;
    void** iter = (void**)m_begin;
    if (end == iter) return result;
    void** iend = end;
    do {
        ElemFNBT* elem = (ElemFNBT*)*iter;
        if (elem) {
            if (elem->m_type == selector && !result) {
                result = elem;
            }
        }
        iter++;
    } while (iter != iend);
    return result;
}
