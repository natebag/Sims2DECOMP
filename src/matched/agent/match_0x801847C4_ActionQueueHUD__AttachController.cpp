// ActionQueueHUD::AttachController(void) @ 0x801847C4 (88B)

struct EController;
struct EControllerManager {
    EController* GetPlayerController(unsigned int playerIdx);
};
struct EController {
    unsigned int AddFilter(unsigned int id, char* name, int val);
};

extern EControllerManager* g_ecm;
extern char g_aqhFilterName[];

struct AQH_AttC {
    char _pad1[780];
    unsigned int m_filterId;
    unsigned int m_filterId2;
    unsigned int m_playerIdx;
    void AttachController();
};

void AQH_AttC::AttachController() {
    if (m_filterId != 0) return;
    EControllerManager* mgr = g_ecm;
    EController* ctrl = mgr->GetPlayerController(m_playerIdx);
    m_filterId = ctrl->AddFilter(0, g_aqhFilterName, 100);
}
