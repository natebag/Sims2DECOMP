void *WM_GetMgr();
void WM_DestroyVis(void *mgr, void *self);

struct WallManipulator_OnDestroy_S {
    void OnDestroy();
};

void WallManipulator_OnDestroy_S::OnDestroy() {
    void *mgr = WM_GetMgr();
    WM_DestroyVis(mgr, this);
}
