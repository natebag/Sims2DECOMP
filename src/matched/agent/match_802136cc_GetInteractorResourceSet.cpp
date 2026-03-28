void *GIRS_GetMgr();
void *GIRS_GetSet(void *mgr, void *self);

struct GetInteractorResourceSet_S {
    void *GetSet();
};

void *GetInteractorResourceSet_S::GetSet() {
    void *mgr = GIRS_GetMgr();
    return GIRS_GetSet(mgr, this);
}
