// 0x8032471C EDatasetManager::GetLoadProgress(void) (8 B)
struct EDatasetManager { char _pad[0xd20]; float m_field; float GetLoadProgress(); };
float EDatasetManager::GetLoadProgress() { return m_field; }
