struct StateMachine {
    char pad[0x1C];
    int m_machineId;

    int GetMachineId(void) const;
};

int StateMachine::GetMachineId(void) const {
    return m_machineId;
}
