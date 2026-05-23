// 0x8031B438 ERModel::IsMorphTarget(void) (8 B)
struct ERModel { char _pad[0x38]; unsigned m_field; unsigned IsMorphTarget(); };
unsigned ERModel::IsMorphTarget() { return m_field; }
