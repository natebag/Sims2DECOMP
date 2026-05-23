// 0x8001EAAC ESimsCam::ForceFullScreen(bool) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x54c]; int m_forceFullScreen; void ForceFullScreen(int); };
void ESimsCam::ForceFullScreen(int v) { m_forceFullScreen = v; }
