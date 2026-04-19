/* FrameEffect::IsEffectRamping(void) at 0x803570B4 (32B) */
// 0x803570B4 (32 bytes)

struct FrameEffect_IER2 {
    char _pad[12];
    int m_state;  // 12
    int IsEffectRamping() const;
};

int FrameEffect_IER2::IsEffectRamping() const {
    int state = m_state;
    int r = 0;
    if (state == 2 || state == 8) r = 1;
    return r;
}
