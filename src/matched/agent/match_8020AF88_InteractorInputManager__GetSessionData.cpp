// FLAGS: -fno-elide-constructors
struct SessionData { char data[32]; };
struct IIM { SessionData* m_sessions; void* GetSessionData(int idx); };
void* IIM::GetSessionData(int idx) {
    if (!m_sessions) return 0;
    return &m_sessions[idx];
}
