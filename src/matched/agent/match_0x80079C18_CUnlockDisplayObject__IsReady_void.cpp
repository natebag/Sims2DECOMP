// 0x80079C18 CUnlockDisplayObject::IsReady(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x74]; unsigned m_isReady; unsigned IsReady(); };
unsigned CUnlockDisplayObject::IsReady() { return m_isReady; }
