/* ERLevel::GetInstance(int) at 0x80238354 (20B) */

struct ERLevel_GI {
    char pad[0x2A2B8];
    void* m_instances[1];
    void* GetInstance(int idx);
};

void* ERLevel_GI::GetInstance(int idx) {
    return m_instances[idx];
}
