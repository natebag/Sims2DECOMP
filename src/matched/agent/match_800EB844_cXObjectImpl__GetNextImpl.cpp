/* cXObjectImpl::GetNextImpl(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x5C];
    void* m_nextImpl;

    void* GetNextImpl(void);
};

void* cXObjectImpl::GetNextImpl(void) {
    return m_nextImpl;
}
