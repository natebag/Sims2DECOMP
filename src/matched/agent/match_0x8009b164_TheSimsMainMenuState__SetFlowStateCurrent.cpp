struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct TheSimsMainMenuState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void TheSimsMainMenuState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
