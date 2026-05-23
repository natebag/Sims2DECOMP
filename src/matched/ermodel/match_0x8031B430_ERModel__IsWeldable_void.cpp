// 0x8031B430 ERModel::IsWeldable(void) (8 B)
struct ERModel { char _pad[0x20]; unsigned m_field; unsigned IsWeldable(); };
unsigned ERModel::IsWeldable() { return m_field; }
