struct S { int m_id; };
struct SM { char p[0x48]; S* m_call; int GetCallingStateId() const; };
int SM::GetCallingStateId() const { return m_call->m_id; }
