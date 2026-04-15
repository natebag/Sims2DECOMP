// 0x800B6464 FamilyImpl::GetNetWorth (60B) — MI vcall offset 0x38/0x3C

typedef unsigned char u8;

extern u8* g_familyMgr;  // SDA @ -21476(r13)

class FamilyImpl;

int FamilyImpl_GetNetWorth(FamilyImpl* self) {
    u8* mgr = g_familyMgr;
    u8* vt = *(u8**)mgr;
    short adj = *(short*)(vt + 0x38);
    int (*fn)(u8*, FamilyImpl*) = *(int (**)(u8*, FamilyImpl*))(vt + 0x3C);
    return fn(mgr + adj, self);
}
