// ActionQueueHUD::DetachController(void) @ 0x8018481C (80B)

struct EController;
struct EControllerManager {
    EController* GetPlayerController(unsigned int playerIdx);
};
struct EController {
    void RemoveFilter(unsigned int filterId);
};

extern EControllerManager* g_ecm;

struct AQH_DetC {
    char _pad1[780];
    unsigned int m_filterId;
    unsigned int m_filterId2;
    unsigned int m_playerIdx;
    void DetachController();
};

void AQH_DetC::DetachController() {
    if (m_filterId == 0) return;
    EControllerManager* mgr = g_ecm;
    EController* ctrl = mgr->GetPlayerController(m_playerIdx);
    ctrl->RemoveFilter(m_filterId);
    m_filterId = 0;
}
