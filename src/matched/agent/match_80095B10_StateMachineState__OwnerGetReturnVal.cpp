// 0x80095B10 (12 bytes)
class StateMachine {
public:
    char pad[144];
    int m_returnVal;
};

class StateMachineState {
public:
    int pad[2];
    StateMachine *m_owner;

    int OwnerGetReturnVal(void);
};

int StateMachineState::OwnerGetReturnVal(void) {
    return m_owner->m_returnVal;
}
