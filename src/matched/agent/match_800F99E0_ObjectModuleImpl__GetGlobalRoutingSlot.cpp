/* ObjectModuleImpl::GetGlobalRoutingSlot(int) - 16 bytes */

class ObjectModuleImpl {
public:
    char pad[0x2078];
    char* m_globalRoutingSlots;

    char* GetGlobalRoutingSlot(int index);
};

char* ObjectModuleImpl::GetGlobalRoutingSlot(int index) {
    return m_globalRoutingSlots + index * 60;
}
