struct TheSimsStateMachine {
    int GetFlowStateRequest(void);
};

struct InLevelBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int GetFlowStateRequest(void);
};

int InLevelBaseState::GetFlowStateRequest(void) {
    return m_owner->GetFlowStateRequest();
}
