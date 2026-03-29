struct S { int m_id; };
struct SM { char p[0x44]; S* m_last; int GetLastStateId() const; };
int SM::GetLastStateId() const { return m_last->m_id; }
