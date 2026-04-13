// 0x803570D4 FrameEffect::IsEffectRunning (24b)
struct FrameEffect {
    int m_state;
    int IsEffectRunning() const;
};

int FrameEffect::IsEffectRunning() const {
    int result = 1;
    if (m_state != 1) return result;
    result = 0;
    return result;
}
