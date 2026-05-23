// 0x80078FDC CUnlockDisplay::IsDone(void) (8 B)
struct CUnlockDisplay { char _pad[0x45c]; unsigned m_isDone; unsigned IsDone(); };
unsigned CUnlockDisplay::IsDone() { return m_isDone; }
