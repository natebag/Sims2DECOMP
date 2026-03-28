struct TheSimsStateMachine {
    int GetFlowStateRequest(void);
};

struct TheSimsMainMenuState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int GetFlowStateRequest(void);
};

int TheSimsMainMenuState::GetFlowStateRequest(void) {
    return m_owner->GetFlowStateRequest();
}
