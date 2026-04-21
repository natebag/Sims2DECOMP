// 0x803573BC (136B) Bloom::EffectStateChanged(FrameEffect::EffectState)
// On state 2 or 8, copy 11-word BloomSettings from offset 64 to offset 108.

class FrameEffect {
public:
    enum EffectState {};
};

struct BloomSettings {
    int fields[11];
};

class Bloom {
public:
    char pad[64];
    BloomSettings m_current;
    BloomSettings m_target;
    void EffectStateChanged(FrameEffect::EffectState state);
};

void Bloom::EffectStateChanged(FrameEffect::EffectState state) {
    if (state != (FrameEffect::EffectState)2 && state != (FrameEffect::EffectState)8) return;
    m_target = m_current;
}
