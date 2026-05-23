// 0x800569F4 ISimInstance::SetCursFlags(unsigned (8 B)
struct ISimInstance { char _pad[0x32c]; unsigned m_cursFlags; void SetCursFlags(unsigned); };
void ISimInstance::SetCursFlags(unsigned flags) { m_cursFlags = flags; }
