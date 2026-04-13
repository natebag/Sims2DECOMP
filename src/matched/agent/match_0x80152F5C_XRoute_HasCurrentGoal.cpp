// 0x80152f5c XRoute::HasCurrentGoal (24b)

struct XRoute {
    int pad[21];
    int m_goal;
    int HasCurrentGoal();
};

int XRoute::HasCurrentGoal() {
    int r = 1;
    if (m_goal == -1) r = 0;
    return r;
}
