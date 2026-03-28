/* cXObjectImpl::GetModule(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x58];
    void* m_module;

    void* GetModule(void);
};

void* cXObjectImpl::GetModule(void) {
    return m_module;
}
