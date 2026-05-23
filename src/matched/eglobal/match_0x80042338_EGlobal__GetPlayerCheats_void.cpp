// 0x80042338 EGlobal::GetPlayerCheats(void) (32 B)
// FLAGS: -fno-schedule-insns
struct EGlobal { char _pad[0x9c]; unsigned short m_playerCheats; char _pad2[0x362]; unsigned m_noCheats; unsigned GetPlayerCheats(); };
unsigned EGlobal::GetPlayerCheats() { if (m_noCheats) return 0xFFFF; return m_playerCheats; }
