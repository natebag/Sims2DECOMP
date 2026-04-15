// 0x800B6428 FamilyImpl::GetFriendCount (60B) — MI vcall via SDA -21476

typedef unsigned char u8;

extern u8* g_familyMgr;  // SDA @ -21476(r13)

class FamilyImpl;

int FamilyImpl_GetFriendCount(FamilyImpl* self) {
    u8* mgr = g_familyMgr;
    u8* vt = *(u8**)mgr;
    short adj = *(short*)(vt + 0x30);
    int (*fn)(u8*, FamilyImpl*) = *(int (**)(u8*, FamilyImpl*))(vt + 0x34);
    return fn(mgr + adj, self);
}
