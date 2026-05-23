// 0x80030954 ERoomWall::GetShortDistToCam(int) (16 B)
// FLAGS: -fno-schedule-insns
struct ERoomWall { char _pad[0x34]; float m_shortDistToCam[9]; float GetShortDistToCam(int); };
float ERoomWall::GetShortDistToCam(int wallId) { return m_shortDistToCam[wallId]; }
