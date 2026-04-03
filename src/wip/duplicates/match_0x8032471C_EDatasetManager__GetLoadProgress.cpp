struct EDatasetManager {
    char _pad[0xd20];
    float m_loadProgress;
    float GetLoadProgress() const;
};
float EDatasetManager::GetLoadProgress() const { return m_loadProgress; }
