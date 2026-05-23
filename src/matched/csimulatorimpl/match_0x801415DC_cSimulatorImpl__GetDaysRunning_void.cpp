// 0x801415DC cSimulatorImpl::GetDaysRunning(void) (8 B)
struct cSimulatorImpl { char _pad[0x4c]; short m_daysRunning; int GetDaysRunning(); };
int cSimulatorImpl::GetDaysRunning() { return m_daysRunning; }
