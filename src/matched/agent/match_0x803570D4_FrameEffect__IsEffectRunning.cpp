/* FrameEffect::IsEffectRunning(void) at 0x803570D4 (24B) */
// 0x803570D4 (24 bytes)

struct FrameEffect_IER {
    char _pad[12];
    int m_state;  // 12
    int IsEffectRunning() const;
};

int FrameEffect_IER::IsEffectRunning() const {
    if (m_state != 1) return 1;
    return 0;
}
