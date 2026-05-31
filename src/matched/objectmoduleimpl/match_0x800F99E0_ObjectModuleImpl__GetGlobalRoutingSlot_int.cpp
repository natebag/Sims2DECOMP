// FLAGS: -fno-schedule-insns
// 0x800F99E0 ObjectModuleImpl::GetGlobalRoutingSlot(int) (16B)
// mulli r4,r4,60; lwz r3,0x2078(r3); add r3,r3,r4; blr
// &m_routingSlots[index], element stride 60 bytes
struct RoutingSlot { char data[60]; };

struct ObjectModuleImpl {
    char pad[0x2078];
    RoutingSlot* m_routingSlots;  // 0x2078
    RoutingSlot* GetGlobalRoutingSlot(int index);
};

RoutingSlot* ObjectModuleImpl::GetGlobalRoutingSlot(int index) {
    return &m_routingSlots[index];
}
