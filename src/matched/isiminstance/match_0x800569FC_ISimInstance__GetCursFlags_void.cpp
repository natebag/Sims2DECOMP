// 0x800569FC ISimInstance::GetCursFlags(void) (8 B)
struct ISimInstance { char _pad[0x32c]; unsigned m_cursFlags; unsigned GetCursFlags(); };
unsigned ISimInstance::GetCursFlags() { return m_cursFlags; }
