class FreeResourceManager { char pad[3232]; int m_val; public: int GetUnreferencedResourceCount(); };
int FreeResourceManager::GetUnreferencedResourceCount() { return m_val; }
