// 0x8010EC30 cXObjectImpl::TryHUDManage(StackElem*, XPrimParam*) (208B)
//
// 1. Check g_hudManager (non-SDA global at 0x80475BC8). If null → return {0, 0}
// 2. InterpValue(this, param->byte2, param->short0, NULL, NULL, &local_s1)
//    If returns {-1, -1} → return {0, 0}
// 3. InterpValue(this, param->byte6, param->short4, NULL, NULL, &local_s2)
//    If returns {-1, -1} → return {0, 0}
// 4. Call g_hudManager->Method(local_s1, param->byte3, local_s2) via free helper bl
// 5. If result == 0 → return {0, 0}, else return {0, 1}

extern long long InterpValue(void* self, unsigned char b, short s, void* p1, void* p2, short* out);
extern int HUDManager_Process(void* mgr, short s1, unsigned char b, short s2);
extern char g_hudManager[16];

struct cXObjImplTHM {
    long long TryHUDManage(void* se, void* param);
};

long long cXObjImplTHM::TryHUDManage(void* /*se*/, void* param) {
    void* mgr = *(void**)g_hudManager;
    if (mgr == 0) return 0LL;

    short s1, s2;
    unsigned char* p = (unsigned char*)param;
    long long iv1 = InterpValue(this, p[2], *(short*)p, (void*)0, (void*)0, &s1);
    if (iv1 == -1LL) return 0LL;

    long long iv2 = InterpValue(this, p[6], *(short*)(p + 4), (void*)0, (void*)0, &s2);
    if (iv2 == -1LL) return 0LL;

    int result = HUDManager_Process(*(void**)g_hudManager, s1, p[3], s2);
    if (result == 0) return 0LL;
    return 1LL;
}
