// 0x80096B34 (8 bytes)
class StateMachine {
public:
    char pad[40];
    float m_frameDeltaTime;

    float GetFrameDeltaTime(void) const;
};

float StateMachine::GetFrameDeltaTime(void) const {
    return m_frameDeltaTime;
}
