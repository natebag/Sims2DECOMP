/* cXObjectImpl::GetSelector(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x8C];
    void* m_selector;

    void* GetSelector(void);
};

void* cXObjectImpl::GetSelector(void) {
    return m_selector;
}
