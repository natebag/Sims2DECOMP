/* cXObjectImpl::GetAdultAnimTable(void) - 36 bytes */

struct ObjSelector {
    void* GetAdultAnimTable(void);
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetAdultAnimTable(void);
};

void* cXObjectImpl::GetAdultAnimTable(void) {
    return m_selector->GetAdultAnimTable();
}
