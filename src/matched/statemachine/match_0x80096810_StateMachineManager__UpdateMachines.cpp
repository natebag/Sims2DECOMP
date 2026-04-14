// 0x80096810 (44 bytes)
struct StateMachineManager {
    int* m_begin;  // 0x00
    int* m_end;    // 0x04

    void UpdateMachine(float dt);
    static void UpdateMachines(float dt);
};

extern StateMachineManager* g_stateMachineManager;

void StateMachineManager::UpdateMachines(float dt) {
    StateMachineManager* mgr = g_stateMachineManager;
    if (mgr != 0) {
        mgr->UpdateMachine(dt);
    }
}
