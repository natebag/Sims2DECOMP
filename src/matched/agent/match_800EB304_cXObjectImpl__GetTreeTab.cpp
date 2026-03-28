/* cXObjectImpl::GetTreeTab(void) - 36 bytes */

struct ObjSelector {
    void* GetTreeTab(void);
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetTreeTab(void);
};

void* cXObjectImpl::GetTreeTab(void) {
    return m_selector->GetTreeTab();
}
