// 0x80035314 ESim::GetPerson(void) (8 B)
struct ESim { char _pad[0x3d0]; unsigned m_person; unsigned GetPerson(); };
unsigned ESim::GetPerson() { return m_person; }
