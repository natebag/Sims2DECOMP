// 0x802B6218 AptPrototype::GetSuperConstructor(void) (8 B)
struct AptPrototype { char _pad[0x20]; unsigned m_field; unsigned GetSuperConstructor(); };
unsigned AptPrototype::GetSuperConstructor() { return m_field; }
