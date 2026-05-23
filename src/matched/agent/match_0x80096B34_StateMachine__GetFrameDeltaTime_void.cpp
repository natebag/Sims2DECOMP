// 0x80096B34 StateMachine::GetFrameDeltaTime(void) (8 B)
struct StateMachine { char _pad[0x28]; float m_frameDeltaTime; float GetFrameDeltaTime(); };
float StateMachine::GetFrameDeltaTime() { return m_frameDeltaTime; }
