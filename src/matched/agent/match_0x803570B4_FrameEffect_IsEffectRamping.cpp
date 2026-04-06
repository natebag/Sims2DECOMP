/* 0x803570B4 (32 bytes)
   FrameEffect::IsEffectRamping(void) const */

typedef unsigned int u32;

struct FrameEffect {
    char _pad[0xC];
    u32 m_state;
    
    bool IsEffectRamping(void) const;
};

bool FrameEffect::IsEffectRamping(void) const {
    return m_state == 2 || m_state == 8;
}
