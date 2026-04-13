// 0x800EAA48 cXObjectImpl::SetMiscFlag (32B)

struct cXObjSMF {
    char pad[0x84];
    int m_miscFlags;
    void SetMiscFlag(int flag, int set);
};

void cXObjSMF::SetMiscFlag(int flag, int set) {
    int flags = m_miscFlags;
    flags = flags & ~flag;
    m_miscFlags = flags;
    if (set == 0) return;
    flags = flags | flag;
    m_miscFlags = flags;
}
