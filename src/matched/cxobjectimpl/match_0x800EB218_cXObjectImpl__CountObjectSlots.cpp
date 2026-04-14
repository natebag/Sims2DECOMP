// 0x800EB218 cXObjectImpl::CountObjectSlots (24B)

struct cXObj_COS {
    char pad[0x90];
    int m_start;
    int m_end;
    int CountObjectSlots();
};

int cXObj_COS::CountObjectSlots() {
    return ((m_end - m_start) >> 5) - 1;
}
