class ArcFileInfo { char pad[0]; int m_val; public: int GetName(); };
int ArcFileInfo::GetName() { return m_val; }
