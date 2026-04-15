// 0x80153248 XRoute::GetCurrentGoal (20B) — &m_begin[m_currentIndex]

struct Goal { char pad[16]; };

struct XRoute {
    Goal* m_begin;
    char pad[80];
    int m_currentIndex;    // +84
    Goal* GetCurrentGoal();
};

Goal* XRoute::GetCurrentGoal() {
    return &m_begin[m_currentIndex];
}
