// 0x800961B4 (8 bytes)
class StateMachine {
public:
    char pad[80];
    float m_timeInState;

    float GetTimeInState(void) const;
};

float StateMachine::GetTimeInState(void) const {
    return m_timeInState;
}
