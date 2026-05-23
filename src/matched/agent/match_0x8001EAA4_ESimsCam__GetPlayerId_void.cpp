// 0x8001EAA4 ESimsCam::GetPlayerId(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x4]; int m_playerId; int GetPlayerId(); };
int ESimsCam::GetPlayerId() { return m_playerId; }
