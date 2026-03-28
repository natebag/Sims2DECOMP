class ArcFileInfo { char pad[12]; int m_val; public: int GetCopiedSize(); };
int ArcFileInfo::GetCopiedSize() { return m_val; }
