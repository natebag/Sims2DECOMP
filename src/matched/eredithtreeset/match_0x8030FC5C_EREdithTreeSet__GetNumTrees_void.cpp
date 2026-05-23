// 0x8030FC5C EREdithTreeSet::GetNumTrees(void) (8 B)
struct EREdithTreeSet { char _pad[0x18]; unsigned m_field; unsigned GetNumTrees(); };
unsigned EREdithTreeSet::GetNumTrees() { return m_field; }
