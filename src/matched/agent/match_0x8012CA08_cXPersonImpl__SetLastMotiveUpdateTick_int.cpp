// 0x8012CA08 cXPersonImpl::SetLastMotiveUpdateTick(int) (8 B)
struct cXPersonImpl { char _pad[0x538]; unsigned m_lastMotiveUpdateTick; void SetLastMotiveUpdateTick(int); };
void cXPersonImpl::SetLastMotiveUpdateTick(int val) { m_lastMotiveUpdateTick = val; }
