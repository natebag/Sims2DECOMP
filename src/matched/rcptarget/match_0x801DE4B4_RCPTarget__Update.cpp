// 0x801DE4B4 (128B) RCPTarget::Update(void)
// Float decrement timer with virtual call on expiry.

extern float g_rcpTargetThreshold __attribute__((section(".data")));
extern float g_rcpTargetDecrement;

struct RCPTarget {
    char pad[0x120];
    void* m_callback;
    char pad2[0x1c];
    float m_timer;
    int m_expired;
    
    void Update();
};

void RCPTarget::Update() {
    if (m_expired == 0) {
        if (m_timer > g_rcpTargetThreshold) {
            m_timer -= g_rcpTargetDecrement;
            if (m_timer <= g_rcpTargetThreshold) {
                m_expired = 1;
                if (m_callback != 0) {
                    char* vt = *(char**)m_callback;
                    short adj = *(short*)(vt + 8);
                    void (*func)(char*) = *(void (**)(char*))(vt + 12);
                    func((char*)m_callback + adj);
                }
            }
        }
    }
}
