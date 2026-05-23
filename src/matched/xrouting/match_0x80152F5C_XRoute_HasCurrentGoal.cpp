// 0x80152F5C XRoute::HasCurrentGoal() (24B) — m_currentGoal != -1
// Returns 1 if there is a current goal (m_currentGoal != -1), 0 otherwise.

struct XRoute {
    char pad[84];        // +0x00..+0x53
    int m_currentGoal;   // +0x54
    bool HasCurrentGoal();
};

bool XRoute::HasCurrentGoal() {
    if (m_currentGoal != -1) return 1;
    return 0;
}
