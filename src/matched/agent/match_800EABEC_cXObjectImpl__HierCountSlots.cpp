/* cXObjectImpl::HierCountSlots(void) - 20 bytes */

class cXObjectImpl {
public:
    char pad[0x90];
    char* m_hierSlotsBegin;
    char* m_hierSlotsEnd;

    int HierCountSlots(void);
};

int cXObjectImpl::HierCountSlots(void) {
    return ((int)m_hierSlotsEnd - (int)m_hierSlotsBegin) >> 5;
}
