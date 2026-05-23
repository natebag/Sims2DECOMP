/* 0x80238354 (20 bytes) - ERLevel::GetInstance(int) */
struct ERLevel {
    char pad[0x2A2B8];
    void* m_instances[1];
    void* GetInstance(int idx);
};

void* ERLevel::GetInstance(int idx) {
    return m_instances[idx];
}
