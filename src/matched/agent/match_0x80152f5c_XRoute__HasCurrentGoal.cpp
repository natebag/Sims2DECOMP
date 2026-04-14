// 0x80152f5c XRoute::HasCurrentGoal(void) (24B)

struct XRoute {
    char pad[0x54];
    int m_currentGoal;
    int HasCurrentGoal(void);
};

int XRoute::HasCurrentGoal(void) {
    return m_currentGoal != -1;
}
