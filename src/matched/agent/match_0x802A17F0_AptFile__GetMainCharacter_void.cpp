// 0x802A17F0 AptFile::GetMainCharacter(void) (8 B)
struct AptFile { char _pad[0x10]; unsigned m_field; unsigned GetMainCharacter(); };
unsigned AptFile::GetMainCharacter() { return m_field; }
