// 0x80318B00 ERModel::GetLatticeCount(void) (8 B)
struct ERModel { char _pad[0x114]; unsigned m_field; unsigned GetLatticeCount(); };
unsigned ERModel::GetLatticeCount() { return m_field; }
