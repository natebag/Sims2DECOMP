// 0x80011EEC AwarenessManager::AwarenessManager(void) (96 B)
// Scheduler hoists last-float + last-int to front; put m_30/m_0 last in source
extern float kAwarenessZero[4];   // 0.0f at 0x803CDC50
extern int kAwarenessVTable[3];   // vtable at 0x8045ADD0

struct AwarenessManager {
    int m_0;       // 0x00
    char pad[8];   // 0x04-0x0B
    float m_0C;    // 0x0C
    float m_10;    // 0x10
    int m_14;      // 0x14
    int m_18;      // 0x18
    int m_1C;      // 0x1C
    float m_20;    // 0x20
    int m_24;      // 0x24
    int m_28;      // 0x28
    float m_2C;    // 0x2C
    float m_30;    // 0x30
    int m_34;      // 0x34
    int m_38;      // 0x38
    float m_3C;    // 0x3C
    int m_40;      // 0x40
    int m_44;      // 0x44
    AwarenessManager();
};

AwarenessManager::AwarenessManager() {
    float zero = kAwarenessZero[0];
    m_44 = (int)kAwarenessVTable;
    m_14 = -1;
    m_0C = zero;
    m_10 = zero;
    m_18 = 0;
    m_1C = 0;
    m_20 = zero;
    m_40 = 0;
    m_3C = zero;
    m_24 = 0;
    m_28 = 0;
    m_2C = zero;
    m_34 = 0;
    m_38 = 0;
    m_30 = zero;
    m_0 = 0;
}
