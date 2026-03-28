void *SMI_GetMgr();
void SMI_DestroyVis(void *mgr, void *self);

struct SocialModeInteractor_OnDestroy_S {
    void OnDestroy();
};

void SocialModeInteractor_OnDestroy_S::OnDestroy() {
    void *mgr = SMI_GetMgr();
    SMI_DestroyVis(mgr, this);
}
