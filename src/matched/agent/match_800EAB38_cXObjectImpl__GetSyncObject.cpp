/* cXObjectImpl::GetSyncObject(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0xDC];
    void* m_syncObject;

    void* GetSyncObject(void);
};

void* cXObjectImpl::GetSyncObject(void) {
    return m_syncObject;
}
