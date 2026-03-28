/* cXObjectImpl::GetSelector(void) const - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x8C];
    void* m_selector;

    void* GetSelector(void) const;
};

void* cXObjectImpl::GetSelector(void) const {
    return m_selector;
}
