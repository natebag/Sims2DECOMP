/* cXObjectImpl::GetBehavior(void) - 12 bytes */

struct ObjSelector {
    char pad[0x0C];
    void* m_behavior;
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetBehavior(void);
};

void* cXObjectImpl::GetBehavior(void) {
    return m_selector->m_behavior;
}
