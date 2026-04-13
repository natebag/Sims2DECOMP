// 0x800EAA00 cXObjectImpl::Kill (60B)

typedef void (*KillFn)(void*, short);

struct cXObj_Kill {
    char pad_00[0x58];
    void* m_iface;
    char pad_5C[8];
    short m_index;

    void Kill();
};

void cXObj_Kill::Kill() {
    char* iface = (char*)m_iface;
    short idx = m_index;
    char* vt = *(char**)iface;
    short adj = *(short*)(vt + 0x58);
    KillFn fn = (KillFn)*(void**)(vt + 0x5C);
    fn(iface + adj, idx);
}
