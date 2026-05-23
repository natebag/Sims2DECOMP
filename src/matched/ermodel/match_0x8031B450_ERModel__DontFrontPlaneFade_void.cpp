// 0x8031B450 ERModel::DontFrontPlaneFade(void) (8 B)
struct ERModel { char _pad[0x24]; unsigned m_field; unsigned DontFrontPlaneFade(); };
unsigned ERModel::DontFrontPlaneFade() { return m_field; }
