// 0x80095824 (76B) TheSimsStartScreenStateMachine::Shutdown(void)

struct StateMachineStatus {
    void ShutdownCurState();
};

struct StartScreenVars {
    void Shutdown();
};

extern void StateMachine_DeleteAllStates(void* sm);
extern StartScreenVars* g_startScreenVars;

struct TheSimsStartScreenStateMachine {
    char pad[60];
    StateMachineStatus m_status;

    void Shutdown();
};

void TheSimsStartScreenStateMachine::Shutdown() {
    m_status.ShutdownCurState();
    StateMachine_DeleteAllStates(this);
    g_startScreenVars->Shutdown();
    delete g_startScreenVars;
    g_startScreenVars = 0;
}
