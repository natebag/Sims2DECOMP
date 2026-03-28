/* cXObjectImpl::GetRoutingSlot(int) - 16 bytes */

class cXObjectImpl {
public:
    char pad[0xA0];
    char* m_routingSlots;

    char* GetRoutingSlot(int index);
};

char* cXObjectImpl::GetRoutingSlot(int index) {
    return m_routingSlots + index * 60;
}
