// 0x803572D8 MotionBlur::EffectIsFinishedFadingOut (24b)

struct MotionBlur {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingOut(float f) const;
};

bool MotionBlur::EffectIsFinishedFadingOut(float f) const {
    return f >= m_fadeOutTarget;
}
