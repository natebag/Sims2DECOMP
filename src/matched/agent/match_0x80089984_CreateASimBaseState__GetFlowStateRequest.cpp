struct TheSimsStateMachine {
    int GetFlowStateRequest(void);
};

struct CreateASimBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int GetFlowStateRequest(void);
};

int CreateASimBaseState::GetFlowStateRequest(void) {
    return m_owner->GetFlowStateRequest();
}
