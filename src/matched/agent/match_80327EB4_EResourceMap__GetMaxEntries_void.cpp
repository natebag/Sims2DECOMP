class EResourceMap { char pad[8]; int m_val; public: int GetMaxEntries(); };
int EResourceMap::GetMaxEntries() { return m_val; }
