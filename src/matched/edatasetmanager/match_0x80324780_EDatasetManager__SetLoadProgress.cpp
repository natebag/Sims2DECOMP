struct EDatasetManager {
    char _pad[0xd20];
    float m_loadProgress;
    void SetLoadProgress(float val);
};
void EDatasetManager::SetLoadProgress(float val) { m_loadProgress = val; }
