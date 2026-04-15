// 0x800EB3F4 cXObjectImpl::GetNumRoutingSlots (32B)

struct RoutingSlot { char pad[60]; };

struct cXObjectImpl {
    char pad[160];
    RoutingSlot* m_slotsBegin;
    RoutingSlot* m_slotsEnd;
    int GetNumRoutingSlots();
};

int cXObjectImpl::GetNumRoutingSlots() {
    return m_slotsEnd - m_slotsBegin;
}
