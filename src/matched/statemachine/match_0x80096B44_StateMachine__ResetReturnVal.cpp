struct StateMachine {
    char pad[0x90];
    int m_returnVal;

    void ResetReturnVal(void);
};

void StateMachine::ResetReturnVal(void) {
    m_returnVal = 0;
}
