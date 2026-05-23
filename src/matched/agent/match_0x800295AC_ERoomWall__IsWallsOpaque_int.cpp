// 0x800295AC ERoomWall::IsWallsOpaque(int) (16 B)
// FLAGS: -fno-schedule-insns
struct ERoomWall { char _pad[0x2c]; int m_wallsOpaque[9]; int IsWallsOpaque(int); };
int ERoomWall::IsWallsOpaque(int wallId) { return m_wallsOpaque[wallId]; }
