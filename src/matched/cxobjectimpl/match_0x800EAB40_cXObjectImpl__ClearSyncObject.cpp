// 0x800EAB40 cXObjectImpl::ClearSyncObject (12B)

struct cXObj_ClearSyncObject {
    char pad[0xDC];
    int m_val;
    void ClearSyncObject();
};

void cXObj_ClearSyncObject::ClearSyncObject() {
    m_val = 0;
}
