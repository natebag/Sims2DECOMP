// 0x8001ADA0 ESimsCam::GetControllerFilterId(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x560]; int m_controllerFilterId; int GetControllerFilterId(); };
int ESimsCam::GetControllerFilterId() { return m_controllerFilterId; }
