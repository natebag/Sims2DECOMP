// 0x800EB414 cXObjectImpl::GetRoutingSlot (16B)

struct cXObj_GRS {
    char pad[0xA0];
    char* m_slots;
    void* GetRoutingSlot(int idx);
};

void* cXObj_GRS::GetRoutingSlot(int idx) {
    return m_slots + idx * 60;
}
