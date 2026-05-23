// 0x8003535C ESim::GetPlumbBobState(void) (8 B)
struct ESim { char _pad[0x3ec]; unsigned m_plumbBobState; unsigned GetPlumbBobState(); };
unsigned ESim::GetPlumbBobState() { return m_plumbBobState; }
