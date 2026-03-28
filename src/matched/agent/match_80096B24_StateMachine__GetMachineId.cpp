// 0x80096B24 (8 bytes)
class StateMachine {
public:
    char pad[28];
    int m_machineId;

    int GetMachineId(void) const;
};

int StateMachine::GetMachineId(void) const {
    return m_machineId;
}
