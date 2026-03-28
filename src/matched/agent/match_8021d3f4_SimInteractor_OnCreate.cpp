void *SI_GetMgr();
void SI_CreateVis(void *mgr, void *self);

struct SimInteractor_OnCreate_S {
    void OnCreate();
};

void SimInteractor_OnCreate_S::OnCreate() {
    void *mgr = SI_GetMgr();
    SI_CreateVis(mgr, this);
}
