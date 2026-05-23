// 0x80318B08 ERModel::GetDummyCount(void) (8 B)
struct ERModel { char _pad[0x120]; unsigned m_field; unsigned GetDummyCount(); };
unsigned ERModel::GetDummyCount() { return m_field; }
