// 0x803570B4 FrameEffect::IsEffectRamping (32b)
struct FrameEffect {
    int m_state;
    int IsEffectRamping() const;
};

int FrameEffect::IsEffectRamping() const {
    int result = 0;
    if (m_state == 2 || m_state == 8) result = 1;
    return result;
}
