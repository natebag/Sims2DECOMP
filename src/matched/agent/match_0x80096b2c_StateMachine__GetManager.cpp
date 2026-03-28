struct StateMachineManager;

struct StateMachine {
    char pad[0x20];
    StateMachineManager *m_manager;

    StateMachineManager *GetManager(void) const;
};

StateMachineManager *StateMachine::GetManager(void) const {
    return m_manager;
}
