// 0x8031B448 ERModel::AreMatsInDLs(void) (8 B)
struct ERModel { char _pad[0x8c]; unsigned m_field; unsigned AreMatsInDLs(); };
unsigned ERModel::AreMatsInDLs() { return m_field; }
