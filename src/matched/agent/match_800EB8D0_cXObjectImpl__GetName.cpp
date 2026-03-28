/* cXObjectImpl::GetName(void) const - 12 bytes */

struct ObjSelector {
    char pad[0x14];
    void* m_name;
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetName(void) const;
};

void* cXObjectImpl::GetName(void) const {
    return m_selector->m_name;
}
