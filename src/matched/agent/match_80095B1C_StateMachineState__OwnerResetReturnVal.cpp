// 0x80095B1C (16 bytes)
class StateMachine {
public:
    char pad[144];
    int m_returnVal;
};

class StateMachineState {
public:
    int pad[2];
    StateMachine *m_owner;

    void OwnerResetReturnVal(void);
};

void StateMachineState::OwnerResetReturnVal(void) {
    m_owner->m_returnVal = 0;
}
