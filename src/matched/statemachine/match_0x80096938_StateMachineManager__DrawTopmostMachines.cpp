// 0x80096938 (52 bytes)
struct ERC;

struct StateMachineManager {
    void DrawTopmostMachine(ERC* rc);
    static void DrawTopmostMachines(ERC* rc);
};

extern StateMachineManager* g_stateMachineManager;

void StateMachineManager::DrawTopmostMachines(ERC* rc) {
    StateMachineManager* mgr = g_stateMachineManager;
    if (mgr != 0) {
        mgr->DrawTopmostMachine(rc);
    }
}
