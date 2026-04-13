// 0x800EB004 cXObjectImpl::GetIdleStatus (60B)

typedef void* (*DispatchFn)(void*, short);

struct cXObj_GIS {
    char pad_00[0x58];
    void* m_iface;
    char pad_5C[8];
    short m_index;

    void* GetIdleStatus();
};

void* cXObj_GIS::GetIdleStatus() {
    char* iface = (char*)m_iface;
    short idx = m_index;
    char* vt = *(char**)iface;
    short adj = *(short*)(vt + 0x238);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x23C);
    return fn(iface + adj, idx);
}
