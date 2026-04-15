// 0x800F99F0 ObjectModuleImpl::GetNumGlobalRoutingSlots (32B)
// Pointer diff / sizeof(RoutingSlot) via magic-number division

struct RoutingSlot {
    char pad[60];  // sizeof must match the magic division
};

struct ObjectModuleImpl {
    char pad[8312];
    RoutingSlot* m_slotsBegin;
    RoutingSlot* m_slotsEnd;
    int GetNumGlobalRoutingSlots();
};

int ObjectModuleImpl::GetNumGlobalRoutingSlots() {
    return m_slotsEnd - m_slotsBegin;
}
