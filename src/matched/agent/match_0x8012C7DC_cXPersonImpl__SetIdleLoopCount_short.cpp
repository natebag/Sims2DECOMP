// 0x8012C7DC cXPersonImpl::SetIdleLoopCount(short) (8 B)
struct cXPersonImpl { char _pad[0x540]; short m_idleLoopCount; void SetIdleLoopCount(short); };
void cXPersonImpl::SetIdleLoopCount(short val) { m_idleLoopCount = val; }
