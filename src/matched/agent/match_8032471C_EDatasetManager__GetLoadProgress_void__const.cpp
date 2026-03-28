class EDatasetManager { char pad[3360]; float m_val; public: float GetLoadProgress() const; };
float EDatasetManager::GetLoadProgress() const { return m_val; }
