// 0x802066E0 (84B) InteractorModule::FloorPainter::UpdateStickState(void)

extern float g_FP_stickNeutral[3];  // forces lis+lfs (not sda21)

struct FP_USS {
    char pad[0x34];
    float m_34;
    float m_38;
    char pad2[0x24];
    unsigned char m_60;

    void UpdateStickState();
};

void FP_USS::UpdateStickState() {
    float neutral = g_FP_stickNeutral[0];
    if (m_34 != neutral || m_38 != neutral) {
        unsigned char flags = m_60;
        if (flags & 0x40) {
            m_60 = flags & ~0x80u;
        } else {
            m_60 = flags | 0xC0u;
        }
    } else {
        m_60 &= ~0xC0u;
    }
}
