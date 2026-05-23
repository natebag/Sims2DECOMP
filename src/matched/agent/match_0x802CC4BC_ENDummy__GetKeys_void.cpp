// 0x802CC4BC ENDummy::GetKeys(void) (8 B)
struct ENDummy { char _pad[0x44]; unsigned m_field; unsigned GetKeys(); };
unsigned ENDummy::GetKeys() { return m_field; }
