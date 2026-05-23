// 0x80079C2C CUnlockDisplayObject::IsDone(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x78]; unsigned m_isDone; unsigned IsDone(); };
unsigned CUnlockDisplayObject::IsDone() { return m_isDone; }
