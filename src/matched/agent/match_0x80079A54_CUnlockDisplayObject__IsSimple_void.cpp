// 0x80079A54 CUnlockDisplayObject::IsSimple(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x80]; unsigned m_isSimple; unsigned IsSimple(); };
unsigned CUnlockDisplayObject::IsSimple() { return m_isSimple; }
