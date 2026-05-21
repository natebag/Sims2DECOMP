// 0x80015958 {anonymous}::TurnOffMotionBlur(FrameEffectsManager *) (72B)

class FrameEffect {
public:
    char _pad0[4];
    float m_intensity;
    void Enable(bool);
};

class FrameEffectsManager {
public:
    FrameEffect* MotionBlurObject();
};

namespace { void TurnOffMotionBlur(FrameEffectsManager* mgr); }

void TurnOffMotionBlur(FrameEffectsManager* mgr) {
    if (mgr == 0) return;
    FrameEffect* fx = mgr->MotionBlurObject();
    if (fx == 0) return;
    fx->m_intensity = 0.0f;
    fx->Enable(false);
}
