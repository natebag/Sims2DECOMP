/* cXObjectImpl::GetChildAnimTable(void) - 36 bytes */

struct ObjSelector {
    void* GetChildAnimTable(void);
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetChildAnimTable(void);
};

void* cXObjectImpl::GetChildAnimTable(void) {
    return m_selector->GetChildAnimTable();
}
