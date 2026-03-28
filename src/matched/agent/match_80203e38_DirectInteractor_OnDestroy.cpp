void *DI_GetMgr2();
void DI_DestroyVis(void *mgr, void *self);

struct DirectInteractor_OnDestroy_S {
    void OnDestroy();
};

void DirectInteractor_OnDestroy_S::OnDestroy() {
    void *mgr = DI_GetMgr2();
    DI_DestroyVis(mgr, this);
}
