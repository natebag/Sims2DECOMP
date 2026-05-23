// 0x800AD118 Behavior::GetOwner(void) (8 B)
struct Behavior { char _pad[0x4]; unsigned m_owner; unsigned GetOwner(); };
unsigned Behavior::GetOwner() { return m_owner; }
