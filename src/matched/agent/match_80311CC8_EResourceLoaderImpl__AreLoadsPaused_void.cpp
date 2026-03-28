class EResourceLoaderImpl { char pad[1000]; int m_val; public: int AreLoadsPaused(); };
int EResourceLoaderImpl::AreLoadsPaused() { return m_val; }
