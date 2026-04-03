struct StateMachine {
    char pad[0x28];
    float m_frameDeltaTime;

    float GetFrameDeltaTime(void) const;
};

float StateMachine::GetFrameDeltaTime(void) const {
    return m_frameDeltaTime;
}
