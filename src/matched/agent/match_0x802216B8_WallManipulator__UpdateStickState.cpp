// 0x802216B8 (84B) InteractorModule::WallManipulator::UpdateStickState(void)

extern float g_WM_stickNeutral[3];  // forces lis+lfs (not sda21)

struct WM_USS {
    char pad[0x34];
    float m_34;
    float m_38;
    char pad2[0x88];
    unsigned int m_C4;

    void UpdateStickState();
};

void WM_USS::UpdateStickState() {
    float neutral = g_WM_stickNeutral[0];
    if (m_34 != neutral || m_38 != neutral) {
        unsigned int flags = m_C4;
        if (flags & 0x400) {
            m_C4 = flags & ~0x800u;
        } else {
            m_C4 = flags | 0xC00u;
        }
    } else {
        m_C4 &= ~0xC00u;
    }
}
