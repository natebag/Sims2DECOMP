// 0x8001EABC ESimsCam::SetCenterNew(bool) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x540]; int m_centerNew; void SetCenterNew(int); };
void ESimsCam::SetCenterNew(int v) { m_centerNew = v; }
