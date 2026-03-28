/* cXObjectImpl::CountObjectSlots(void) - 24 bytes */

class cXObjectImpl {
public:
    char pad[0x90];
    char* m_hierSlotsBegin;
    char* m_hierSlotsEnd;

    int CountObjectSlots(void);
};

int cXObjectImpl::CountObjectSlots(void) {
    return (((int)m_hierSlotsEnd - (int)m_hierSlotsBegin) >> 5) - 1;
}
