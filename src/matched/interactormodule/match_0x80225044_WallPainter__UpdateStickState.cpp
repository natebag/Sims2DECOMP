// 0x80225044 (84B) InteractorModule::WallPainter::UpdateStickState(void)

extern float g_WP_stickNeutral[3];  // forces lis+lfs (not sda21)

struct WP_USS {
    char pad[0x34];
    float m_34;
    float m_38;
    char pad2[0x4C];
    unsigned int m_88;

    void UpdateStickState();
};

void WP_USS::UpdateStickState() {
    float neutral = g_WP_stickNeutral[0];
    if (m_34 != neutral || m_38 != neutral) {
        unsigned int flags = m_88;
        if (flags & 0x100) {
            m_88 = flags & ~0x200u;
        } else {
            m_88 = flags | 0x300u;
        }
    } else {
        m_88 &= ~0x300u;
    }
}
