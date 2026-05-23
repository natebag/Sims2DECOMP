// 0x8001EAC4 ESimsCam::GetRoomId(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x544]; unsigned short m_roomId; unsigned short GetRoomId(); };
unsigned short ESimsCam::GetRoomId() { return m_roomId; }
