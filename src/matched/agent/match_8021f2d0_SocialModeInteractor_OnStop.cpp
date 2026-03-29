struct GameData_OS {
    char pad[0x44];
    void *m_hudTarget;
};

extern GameData_OS _gd;
extern void *g_controllerMgr;

void HUDTarget_CloseMenu(void *hud, int personID);
int EControllerMgr_GetPlayerIdx(void *mgr, unsigned int personID);
void *EControllerMgr_GetCtrl(void *mgr, unsigned int index);
void EController_RemFilter(void *ctrl, unsigned int filterID);
void *InteractorMgr_GetInputMgr();
void InteractorInputMgr_CloseSess(void *inputMgr, int personID);

struct SocialModeInteractor_OS {
    int m_personID;
    char pad1[0x60];
    int m_filterID1;
    int m_filterID2;

    void OnStop();
};

void SocialModeInteractor_OS::OnStop() {
    void *hud = _gd.m_hudTarget;
    if (hud != 0) {
        HUDTarget_CloseMenu(hud, m_personID);
    }

    void *mgr = g_controllerMgr;
    int idx = EControllerMgr_GetPlayerIdx(mgr, m_personID);
    void *ctrl = EControllerMgr_GetCtrl(mgr, idx);

    EController_RemFilter(ctrl, m_filterID2);
    EController_RemFilter(ctrl, m_filterID1);

    void *inputMgr = InteractorMgr_GetInputMgr();
    InteractorInputMgr_CloseSess(inputMgr, m_personID);
}
