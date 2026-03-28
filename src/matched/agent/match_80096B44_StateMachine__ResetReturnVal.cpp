// 0x80096B44 (12 bytes)
class StateMachine {
public:
    char pad[144];
    int m_returnVal;

    void ResetReturnVal(void);
};

void StateMachine::ResetReturnVal(void) {
    m_returnVal = 0;
}
