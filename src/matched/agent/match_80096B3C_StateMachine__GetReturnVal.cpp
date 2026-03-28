// 0x80096B3C (8 bytes)
class StateMachine {
public:
    char pad[144];
    int m_returnVal;

    int GetReturnVal(void) const;
};

int StateMachine::GetReturnVal(void) const {
    return m_returnVal;
}
