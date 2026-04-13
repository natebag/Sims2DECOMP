// 0x800B6464 FamilyImpl::GetNetWorth (60B)

typedef void* (*DispatchFn)(void*, void*);

extern void* g_familyMgr;

struct FamilyImpl_GNW {
    void* GetNetWorth();
};

void* FamilyImpl_GNW::GetNetWorth() {
    char* mgr = (char*)g_familyMgr;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x38);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x3C);
    return fn(mgr + adj, this);
}
