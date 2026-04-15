/* 0x801534CC XRoute::ResetGoals(void) (52B) */

struct XRouteGoal {
    char pad[16];
};

class XRoute {
public:
    XRouteGoal* m_begin;    // +0
    XRouteGoal* m_end;      // +4
    char pad[76];
    int m_currentGoal;      // +84
    int m_score;            // +88

    void ResetGoals(void);
};

void XRoute::ResetGoals(void) {
    XRouteGoal* begin = m_begin;
    XRouteGoal* end = m_end;
    for (XRouteGoal* p = begin; p != end; p = (XRouteGoal*)((char*)p + 16)) {
    }
    m_end = begin;
    m_currentGoal = -1;
    m_score = -1;
}
