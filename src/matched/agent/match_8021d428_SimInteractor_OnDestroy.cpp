void *SI_GetMgr2();
void SI_DestroyVis(void *mgr, void *self);

struct SimInteractor_OnDestroy_S {
    void OnDestroy();
};

void SimInteractor_OnDestroy_S::OnDestroy() {
    void *mgr = SI_GetMgr2();
    SI_DestroyVis(mgr, this);
}
