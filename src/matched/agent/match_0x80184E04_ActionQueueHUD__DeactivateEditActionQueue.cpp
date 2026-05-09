// ActionQueueHUD::DeactivateEditActionQueue(void) @ 0x80184E04 (76B)

struct EController;
struct EControllerManager {
    EController* GetPlayerController(unsigned int playerIdx);
};
struct EController {
    void RemoveFilter(unsigned int filterId);
};

extern EControllerManager* g_ecm;

struct AQH_DeactEAQ {
    char _pad1[784];
    unsigned int m_filterId2;
    unsigned int m_playerIdx;
    unsigned char m_active;
    void DeactivateEditActionQueue();
};

void AQH_DeactEAQ::DeactivateEditActionQueue() {
    m_active = 1;
    EControllerManager* mgr = g_ecm;
    EController* ctrl = mgr->GetPlayerController(m_playerIdx);
    ctrl->RemoveFilter(m_filterId2);
    m_filterId2 = 0;
}
