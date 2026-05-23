// 0x80079C68 CUnlockDisplayObject::GetType(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x4]; unsigned m_type; unsigned GetType(); };
unsigned CUnlockDisplayObject::GetType() { return m_type; }
