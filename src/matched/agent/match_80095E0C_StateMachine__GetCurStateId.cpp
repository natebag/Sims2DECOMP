struct S { int m_id; };
struct SM { char p[0x3C]; S* m_cur; int GetCurStateId() const; };
int SM::GetCurStateId() const {
    S* s = m_cur;
    if (s != 0) return s->m_id;
    return -1;
}
