/* 0x80238374 (20 bytes) - ERLevel::GetVisInstance(int) */
struct ERLevel {
    char pad[0x2C2CC];
    int m_visInstances[1];
    int GetVisInstance(int idx);
};

int ERLevel::GetVisInstance(int idx) {
    return m_visInstances[idx];
}
