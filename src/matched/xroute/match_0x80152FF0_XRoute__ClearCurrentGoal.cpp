/* 0x80152FF0 XRoute::ClearCurrentGoal(void) (76B) */

struct XRouteGoal {
    char pad0[8];
    int m_field_8;
    char pad1[4];
};

class XRoute {
public:
    XRouteGoal* m_begin;    // +0
    XRouteGoal* m_end;      // +4
    char pad[76];
    int m_currentGoal;      // +84
    int m_score;            // +88

    void ClearCurrentGoal(void);
};

void XRoute::ClearCurrentGoal(void) {
    int cur = m_currentGoal;
    if (cur == -1) return;
    if (cur >= 0) {
        int n = m_end - m_begin;
        if ((unsigned)cur < (unsigned)n) {
            XRouteGoal* p = (XRouteGoal*)((char*)m_begin + (cur << 4));
            p->m_field_8 = 0;
        }
    }
    m_currentGoal = -1;
    m_score = -1;
}
