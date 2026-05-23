// 0x8001AD94 ESimsCam::SetControllerFilterId(unsigned) (12 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x560]; int m_controllerFilterId; int SetControllerFilterId(unsigned); };
int ESimsCam::SetControllerFilterId(unsigned v) { m_controllerFilterId = v; return 1; }
