// 0x800C1D74 Interaction::GetTreeTabEntryIndex(void) (8 B)
struct Interaction { char _pad[0x14]; unsigned m_field; unsigned GetTreeTabEntryIndex(); };
unsigned Interaction::GetTreeTabEntryIndex() { return m_field; }
