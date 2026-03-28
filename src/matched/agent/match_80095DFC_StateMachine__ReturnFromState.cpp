// 0x80095DFC (16 bytes)
class StateMachine {
public:
    char pad[136];
    int m_returnPending;
    int m_returnStateId;

    void ReturnFromState(int stateId);
};

void StateMachine::ReturnFromState(int stateId) {
    m_returnStateId = stateId;
    m_returnPending = 1;
}
