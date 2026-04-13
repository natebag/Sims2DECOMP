// 0x803572C0 MotionBlur::EffectIsFinishedFadingIn (24b)

struct MotionBlur {
    float m_fadeInTarget;
    float m_fadeOutTarget;
    bool EffectIsFinishedFadingIn(float f) const;
};

bool MotionBlur::EffectIsFinishedFadingIn(float f) const {
    return f >= m_fadeInTarget;
}
