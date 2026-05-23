// 0x800C8860 NamespaceSelector::GetTreeSetResource(void) (8 B)
struct NamespaceSelector { char _pad[0x30]; unsigned m_field; unsigned GetTreeSetResource(); };
unsigned NamespaceSelector::GetTreeSetResource() { return m_field; }
