// 0x8031B428 ERModel::IsHierarchical(void) (8 B)
struct ERModel { char _pad[0x14]; unsigned m_field; unsigned IsHierarchical(); };
unsigned ERModel::IsHierarchical() { return m_field; }
