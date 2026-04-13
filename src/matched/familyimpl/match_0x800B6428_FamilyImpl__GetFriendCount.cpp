// 0x800B6428 FamilyImpl::GetFriendCount (60B)

typedef void* (*DispatchFn)(void*, void*);

extern void* g_familyMgr;

struct FamilyImpl_GFC {
    void* GetFriendCount();
};

void* FamilyImpl_GFC::GetFriendCount() {
    char* mgr = (char*)g_familyMgr;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x30);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x34);
    return fn(mgr + adj, this);
}
