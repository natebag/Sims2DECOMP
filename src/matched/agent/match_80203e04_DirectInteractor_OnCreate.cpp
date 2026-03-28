void *DI_GetMgr();
void DI_CreateVis(void *mgr, void *self);

struct DirectInteractor_OnCreate_S {
    void OnCreate();
};

void DirectInteractor_OnCreate_S::OnCreate() {
    void *mgr = DI_GetMgr();
    DI_CreateVis(mgr, this);
}
