struct StateMachine {
    char pad[0x50];
    float m_timeInState;

    float GetTimeInState(void) const;
};

float StateMachine::GetTimeInState(void) const {
    return m_timeInState;
}
