// 0x80152F88 XRoute::GetNthGoal(int) (16B) — &m_begin[n]
// Returns pointer to nth RouteGoal (stride 16B).

struct Goal { char pad[16]; };

struct XRoute {
    Goal* m_begin;
    Goal* GetNthGoal(int n);
};

Goal* XRoute::GetNthGoal(int n) {
    return &m_begin[n];
}
