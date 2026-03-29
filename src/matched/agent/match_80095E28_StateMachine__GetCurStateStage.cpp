struct S { char p[0x0C]; int m_stage; };
struct SM { char p[0x3C]; S* m_cur; int GetCurStateStage() const; };
int SM::GetCurStateStage() const { return m_cur->m_stage; }
