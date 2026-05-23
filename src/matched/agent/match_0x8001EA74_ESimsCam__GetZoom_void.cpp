// 0x8001EA74 ESimsCam::GetZoom(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x448]; float m_zoom; float GetZoom(); };
float ESimsCam::GetZoom() { return m_zoom; }
