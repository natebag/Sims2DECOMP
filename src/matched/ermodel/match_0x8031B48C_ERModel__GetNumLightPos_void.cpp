// 0x8031B48C ERModel::GetNumLightPos(void) (8 B)
struct ERModel { char _pad[0x140]; unsigned m_field; unsigned GetNumLightPos(); };
unsigned ERModel::GetNumLightPos() { return m_field; }
