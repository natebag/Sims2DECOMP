// 0x80016990 ESimsCam::GetFarPlane(void) (12 B)
// FLAGS: -fno-schedule-insns
struct ECamParams { char _pad[0x68]; float m_farPlane; };
struct ESimsCam { ECamParams* m_params; float GetFarPlane(); };
float ESimsCam::GetFarPlane() { return m_params->m_farPlane; }
