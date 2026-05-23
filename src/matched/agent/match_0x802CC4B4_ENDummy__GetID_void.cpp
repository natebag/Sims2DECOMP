// 0x802CC4B4 ENDummy::GetID(void) (8 B)
struct ENDummy { char _pad[0x40]; unsigned m_field; unsigned GetID(); };
unsigned ENDummy::GetID() { return m_field; }
