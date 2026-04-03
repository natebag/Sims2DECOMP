struct StateMachine {
    char pad[0x88];
    int m_returnRequested;
    int m_returnCode;

    void ReturnFromState(int code);
};

void StateMachine::ReturnFromState(int code) {
    m_returnCode = code;
    m_returnRequested = 1;
}
