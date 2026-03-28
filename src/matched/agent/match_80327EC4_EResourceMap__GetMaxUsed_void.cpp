class EResourceMap { char pad[16]; int m_val; public: int GetMaxUsed(); };
int EResourceMap::GetMaxUsed() { return m_val; }
