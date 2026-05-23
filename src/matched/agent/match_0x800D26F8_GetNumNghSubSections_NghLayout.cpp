// 0x800D26F8 GetNumNghSubSections(NghLayout) (8 B)
struct NghLayout { char _pad[0xc]; unsigned m_numSubSections; };
unsigned GetNumNghSubSections(NghLayout* layout) { return layout->m_numSubSections; }
