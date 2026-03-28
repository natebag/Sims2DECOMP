class ArcFileInfo { char pad[8]; int m_val; public: int GetSourceLen(); };
int ArcFileInfo::GetSourceLen() { return m_val; }
