class EResourceMap { char pad[4]; int m_val; public: int GetNumEntries(); };
int EResourceMap::GetNumEntries() { return m_val; }
