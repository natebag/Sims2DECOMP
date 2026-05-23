// 0x80079C60 CUnlockDisplayObject::HasDrawn(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x7c]; unsigned m_hasDrawn; unsigned HasDrawn(); };
unsigned CUnlockDisplayObject::HasDrawn() { return m_hasDrawn; }
