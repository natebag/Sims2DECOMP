// 0x80152F74 XRoute::CountGoals (20B) — (end - begin) / 16

struct Goal { char pad[16]; };

struct XRoute {
    Goal* m_begin;
    Goal* m_end;
    int CountGoals();
};

int XRoute::CountGoals() {
    return m_end - m_begin;
}
