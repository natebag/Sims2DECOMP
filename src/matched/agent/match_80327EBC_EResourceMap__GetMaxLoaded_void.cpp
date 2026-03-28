class EResourceMap { char pad[12]; int m_val; public: int GetMaxLoaded(); };
int EResourceMap::GetMaxLoaded() { return m_val; }
