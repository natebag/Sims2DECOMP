// 0x80321DAC ArcFileInfo::GetSourceLen(void) (8 B)
struct ArcFileInfo { char _pad[0x8]; unsigned m_field; unsigned GetSourceLen(); };
unsigned ArcFileInfo::GetSourceLen() { return m_field; }
