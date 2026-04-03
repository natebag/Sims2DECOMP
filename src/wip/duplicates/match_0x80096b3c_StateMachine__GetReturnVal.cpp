struct StateMachine {
    char pad[0x90];
    int m_returnVal;

    int GetReturnVal(void) const;
};

int StateMachine::GetReturnVal(void) const {
    return m_returnVal;
}
