/* cXObjectImpl::ClearSyncObject(void) - 12 bytes */

class cXObjectImpl {
public:
    char pad[0xDC];
    void* m_syncObject;

    void ClearSyncObject(void);
};

void cXObjectImpl::ClearSyncObject(void) {
    m_syncObject = 0;
}
