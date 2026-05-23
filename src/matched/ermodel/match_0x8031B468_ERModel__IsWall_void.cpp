// 0x8031B468 ERModel::IsWall(void) (8 B)
struct ERModel { char _pad[0x30]; unsigned m_field; unsigned IsWall(); };
unsigned ERModel::IsWall() { return m_field; }
