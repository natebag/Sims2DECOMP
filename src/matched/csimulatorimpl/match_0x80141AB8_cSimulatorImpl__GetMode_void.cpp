// 0x80141AB8 cSimulatorImpl::GetMode(void) (8 B)
struct cSimulatorImpl { char _pad[0x3a]; short m_mode; int GetMode(); };
int cSimulatorImpl::GetMode() { return m_mode; }
