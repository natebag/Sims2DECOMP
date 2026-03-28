class EResourceManager { char pad[72]; int m_val; public: int IsInitialized(); };
int EResourceManager::IsInitialized() { return m_val; }
