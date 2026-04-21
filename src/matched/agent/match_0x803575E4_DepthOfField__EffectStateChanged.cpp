// 0x803575E4 (68B) DepthOfField::EffectStateChanged(FrameEffect::EffectState)
// On state 2 or 8, copy 5-word DepthOfFieldSettings from offset 40 to offset 60.

class FrameEffect {
public:
    enum EffectState {};
};

struct DepthOfFieldSettings {
    int fields[5];
};

class DepthOfField {
public:
    char pad[40];
    DepthOfFieldSettings m_current;
    DepthOfFieldSettings m_target;
    void EffectStateChanged(FrameEffect::EffectState state);
};

void DepthOfField::EffectStateChanged(FrameEffect::EffectState state) {
    if (state != (FrameEffect::EffectState)2 && state != (FrameEffect::EffectState)8) return;
    m_target = m_current;
}
