// 0x8031B460 ERModel::DontCull(void) (8 B)
struct ERModel { char _pad[0x2c]; unsigned m_field; unsigned DontCull(); };
unsigned ERModel::DontCull() { return m_field; }
