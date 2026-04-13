// 0x800EB080 cXObjectImpl::ClearIdleStatus (60B)

typedef void* (*DispatchFn)(void*, short);

struct cXObj_CIS {
    char pad_00[0x58];
    void* m_iface;
    char pad_5C[8];
    short m_index;

    void* ClearIdleStatus();
};

void* cXObj_CIS::ClearIdleStatus() {
    char* iface = (char*)m_iface;
    short idx = m_index;
    char* vt = *(char**)iface;
    short adj = *(short*)(vt + 0x230);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x234);
    return fn(iface + adj, idx);
}
