// 0x8012C780 cXPersonImpl::GetIdleState(void) (8 B)
struct cXPersonImpl { char _pad[0x8]; short m_idleState; int GetIdleState(); };
int cXPersonImpl::GetIdleState() { return m_idleState; }
