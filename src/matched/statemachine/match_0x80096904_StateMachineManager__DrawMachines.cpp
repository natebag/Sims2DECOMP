// 0x80096904 (52 bytes)
struct ERC;

struct StateMachineManager {
    void DrawMachine(ERC* rc);
    static void DrawMachines(ERC* rc);
};

extern StateMachineManager* g_stateMachineManager;

void StateMachineManager::DrawMachines(ERC* rc) {
    StateMachineManager* mgr = g_stateMachineManager;
    if (mgr != 0) {
        mgr->DrawMachine(rc);
    }
}
