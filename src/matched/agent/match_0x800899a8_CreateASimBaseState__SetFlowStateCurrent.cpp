struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct CreateASimBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void CreateASimBaseState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
