// 0x8031B458 ERModel::DontInterestFade(void) (8 B)
struct ERModel { char _pad[0x28]; unsigned m_field; unsigned DontInterestFade(); };
unsigned ERModel::DontInterestFade() { return m_field; }
