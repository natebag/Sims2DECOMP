// 0x801E7090 M2MTarget::GetPlayerNum(void) (8 B)
struct M2MTarget { char _pad[0x190]; unsigned m_field; unsigned GetPlayerNum(); };
unsigned M2MTarget::GetPlayerNum() { return m_field; }
