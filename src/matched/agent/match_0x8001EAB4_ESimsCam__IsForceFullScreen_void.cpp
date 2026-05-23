// 0x8001EAB4 ESimsCam::IsForceFullScreen(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x54c]; int m_forceFullScreen; int IsForceFullScreen(); };
int ESimsCam::IsForceFullScreen() { return m_forceFullScreen; }
