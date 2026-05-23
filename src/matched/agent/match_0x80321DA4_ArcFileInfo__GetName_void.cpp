// 0x80321DA4 ArcFileInfo::GetName(void) (8 B)
struct ArcFileInfo { unsigned m_field; unsigned GetName(); };
unsigned ArcFileInfo::GetName() { return m_field; }
