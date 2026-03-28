struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct UrbzCreditsState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void UrbzCreditsState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
