// 0x80078FFC CUnlockDisplay::DonePreloadObject(void) (8 B)
struct CUnlockDisplay { char _pad[0x450]; unsigned m_donePreload; unsigned DonePreloadObject(); };
unsigned CUnlockDisplay::DonePreloadObject() { return m_donePreload; }
