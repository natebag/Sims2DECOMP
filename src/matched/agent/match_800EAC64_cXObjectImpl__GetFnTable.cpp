/* cXObjectImpl::GetFnTable(void) - 36 bytes */

struct ObjSelector {
    void* GetFnTable(void);
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetFnTable(void);
};

void* cXObjectImpl::GetFnTable(void) {
    return m_selector->GetFnTable();
}
