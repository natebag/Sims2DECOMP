struct TheSimsStateMachine {
    int GetFlowStateRequest(void);
};

struct PreGameFreeplayState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int GetFlowStateRequest(void);
};

int PreGameFreeplayState::GetFlowStateRequest(void) {
    return m_owner->GetFlowStateRequest();
}
