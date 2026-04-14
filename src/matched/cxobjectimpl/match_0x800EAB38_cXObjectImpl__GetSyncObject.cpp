// 0x800EAB38 cXObjectImpl::GetSyncObject (8B)

struct cXObj_GetSyncObject {
    char pad[0xDC];
    int m_val;
    int GetSyncObject();
};

int cXObj_GetSyncObject::GetSyncObject() {
    return m_val;
}
