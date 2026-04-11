/* 0x803570D4 (24 bytes)
   FrameEffect::IsEffectRunning(void) const */

typedef unsigned int u32;

struct FrameEffect {
    char _pad[0xC];
    u32 m_state;
    
    bool IsEffectRunning(void) const;
};

bool FrameEffect::IsEffectRunning(void) const {
    return m_state != 1;
}
