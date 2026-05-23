// 0x80056354 ISimInstance::GetXOb(void) (8 B)
struct ISimInstance { char _pad[0x328]; unsigned m_xob; unsigned GetXOb(); };
unsigned ISimInstance::GetXOb() { return m_xob; }
