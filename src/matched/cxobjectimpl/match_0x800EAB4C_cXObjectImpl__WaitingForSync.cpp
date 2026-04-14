// 0x800EAB4C cXObjectImpl::WaitingForSync (8B)

struct cXObj_WaitingForSync {
    char pad[0xE4];
    int m_val;
    int WaitingForSync();
};

int cXObj_WaitingForSync::WaitingForSync() {
    return m_val;
}
