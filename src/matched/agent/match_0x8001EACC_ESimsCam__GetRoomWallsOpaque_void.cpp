// 0x8001EACC ESimsCam::GetRoomWallsOpaque(void) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x548]; int m_roomWallsOpaque; int GetRoomWallsOpaque(); };
int ESimsCam::GetRoomWallsOpaque() { return m_roomWallsOpaque; }
