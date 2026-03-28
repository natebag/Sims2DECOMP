/* cXObjectImpl::GetFolder(void) - 12 bytes */

struct ObjSelector {
    char pad[0x50];
    void* m_folder;
};

class cXObjectImpl {
public:
    char pad[0x8C];
    ObjSelector* m_selector;

    void* GetFolder(void);
};

void* cXObjectImpl::GetFolder(void) {
    return m_selector->m_folder;
}
