// 0x80022FA8 (132B) ESimsDataManager::GetLoadProgress(void)
// Float division progress with int-to-float magic conversion.

struct ESimsDataManager {
    char pad[0xd20];
    int m_state;
    int m_current;
    int m_total;
    
    float GetLoadProgress();
};

float ESimsDataManager::GetLoadProgress() {
    if (m_state != 1) {
        return 0.0f;
    }
    if (m_total == 0) {
        return 1.0f;
    }
    return (float)m_current / (float)m_total;
}
