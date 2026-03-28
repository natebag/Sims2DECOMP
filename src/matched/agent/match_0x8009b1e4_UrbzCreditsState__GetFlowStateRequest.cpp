struct TheSimsStateMachine {
    int GetFlowStateRequest(void);
};

struct UrbzCreditsState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int GetFlowStateRequest(void);
};

int UrbzCreditsState::GetFlowStateRequest(void) {
    return m_owner->GetFlowStateRequest();
}
