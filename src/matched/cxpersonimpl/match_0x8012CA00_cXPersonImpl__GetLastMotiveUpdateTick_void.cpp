// 0x8012CA00 cXPersonImpl::GetLastMotiveUpdateTick(void) (8 B)
struct cXPersonImpl { char _pad[0x538]; unsigned m_lastMotiveUpdateTick; unsigned GetLastMotiveUpdateTick(); };
unsigned cXPersonImpl::GetLastMotiveUpdateTick() { return m_lastMotiveUpdateTick; }
