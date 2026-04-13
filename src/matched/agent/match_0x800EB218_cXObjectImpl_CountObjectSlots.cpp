// 0x800EB218 cXObjectImpl::CountObjectSlots (52b)
struct cXObjectImpl {
    char pad[0x90];
    void* m_slotArrayStart;
    void* m_slotArrayEnd;
    int CountObjectSlots();
};

int cXObjectImpl::CountObjectSlots() {
    return (((int)m_slotArrayEnd - (int)m_slotArrayStart) >> 5) - 1;
}
