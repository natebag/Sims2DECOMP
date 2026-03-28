void *SMI_GetMgr2();
void SMI_CreateVis2(void *mgr, void *self);

struct SocialModeInteractor_OC {
    char pad[0x60];
    short m_targetId;

    void OnCreate();
};

void SocialModeInteractor_OC::OnCreate() {
    void *mgr = SMI_GetMgr2();
    SMI_CreateVis2(mgr, this);
    m_targetId = -1;
}
