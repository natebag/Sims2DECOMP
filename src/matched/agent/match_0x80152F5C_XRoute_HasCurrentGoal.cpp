// 0x80152F5C (24B) XRoute::HasCurrentGoal(void)

struct XRoute {
    char pad[84];
    int m_goal;
    bool HasCurrentGoal();
};

bool XRoute::HasCurrentGoal() {
    if (m_goal != -1) return 1;
    return 0;
}
