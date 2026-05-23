// 0x800AD120 Behavior::GetLanguage(void) (8 B)
struct Behavior { char _pad[0x8]; unsigned m_language; unsigned GetLanguage(); };
unsigned Behavior::GetLanguage() { return m_language; }
