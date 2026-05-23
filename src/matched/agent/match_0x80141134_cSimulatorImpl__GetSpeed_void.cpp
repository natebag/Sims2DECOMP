// 0x80141134 cSimulatorImpl::GetSpeed(void) (8 B)
struct cSimulatorImpl { char _pad[0x34]; short m_speed; int GetSpeed(); };
int cSimulatorImpl::GetSpeed() { return m_speed; }
