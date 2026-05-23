// 0x800C1C74 Interaction::GetStackObject(void) (8 B)
struct Interaction { char _pad[0xc]; unsigned m_field; unsigned GetStackObject(); };
unsigned Interaction::GetStackObject() { return m_field; }
