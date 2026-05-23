// 0x800799C4 CUnlockDisplayObject::GetModel(void) (8 B)
struct CUnlockDisplayObject { char _pad[0x14]; unsigned m_model; unsigned GetModel(); };
unsigned CUnlockDisplayObject::GetModel() { return m_model; }
