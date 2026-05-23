// 0x80321DB4 ArcFileInfo::GetCopiedSize(void) (8 B)
struct ArcFileInfo { char _pad[0xc]; unsigned m_field; unsigned GetCopiedSize(); };
unsigned ArcFileInfo::GetCopiedSize() { return m_field; }
